/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> depths;                        // 与上面同步存储行的坐标
    int col = 1;                                       // 维护列号，为了保证根节点和子树一致，初始值取为1，假设有一个虚拟根节点
    int depth = -1;                                    // 维护深度，根节点为0
    int min_col = __INT_MAX__, max_col = __INT_MAX__;  // 维护遍历过程中遇到的最大列号和行号来确定插入的位置

    void traverse(TreeNode *root, bool is_left) {
        if (nullptr == root)
            return;

        col += is_left ? -1 : 1;
        ++depth;

        // 我们需要特判初始的时候的情况
        if (__INT_MAX__ == min_col && __INT_MAX__ == max_col) {
            ret.push_back({root->val});
            depths.push_back({depth});
            min_col = 0, max_col = 0;
        }

        else {
            // 现在该看插入位置了
            // 在头部插入
            if (col < min_col) {
                ret.insert(ret.begin(), {root->val});
                depths.insert(depths.begin(), {depth});
                min_col = col;
            }
            // 在尾部插入
            else if (col > max_col) {
                ret.push_back({root->val});
                depths.push_back({depth});
                max_col = col;
            }
            // 在中间的位置插入，需要考虑顺序，行小优先，行同看值大小
            else {
                // 列号在数组中对应的位置
                int index = col - min_col;
                // 查询depths数组中行号相等的起始位置和结束位置
                int i = 0;
                while (i < depths[index].size() && depths[index][i] < depth)
                    ++i;
                int left = i;  // 找到左边的位置

                if (depths[index].size() == i) {  // 没找到，在末尾插入
                    ret[index].push_back(root->val);
                    depths[index].push_back(depth);
                }
                // 继续查找有边界
                else {
                    while (i < depths[index].size() && depths[index][i] == depth)
                        ++i;

                    int right = i;  // 找到右边的位置(不包含)

                    int pos = binary_search(ret[index], left, right, root->val);
                    ret[index].insert(ret[index].begin() + pos, root->val);
                    depths[index].insert(depths[index].begin() + pos, depth);
                }
            }
        }

        traverse(root->left, true);
        traverse(root->right, false);

        col += is_left ? 1 : -1;
        --depth;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        traverse(root, true);

        return ret;
    }

    // 实现一个二分查找，返回target或者找不到的时候大于target的最小的元素的下标
    int binary_search(vector<int> &nums, int left, int right, int target) {
        while (left < right) {
            int mid = left + right >> 1;

            if (target == nums[mid])
                return mid;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
// @lc code=end
