/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
#include <queue>

class Solution {
public:
    // 层序遍历
    // 需要注意的是，队列中还要存储当前节点相对本层的下标，这个由上层计算得出
    // 为了方便，下标从1开始，这样左子树就是2k-1，右子树就是2k，注意下标包含了空指针的占位
    int widthOfBinaryTree(TreeNode *root) {
        if (nullptr == root)
            return 0;

        queue<pair<TreeNode *, int>> q;
        int res = -1;
        // 根节点入队
        q.push({root, 1});
        while (false == q.empty()) {
            int n = q.size();
            int leftIndex = -1, rightIndex = -1;
            int ref = -1;

            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                // TODO
                // 这里由于int会越界，所以做一个优化，把每层最左边的下标置为1，然后取得相对下标，经验证这样是可以的
                if (0 == i)
                    leftIndex = node.second;
                if (n - 1 == i)
                    rightIndex = node.second;

                if (node.first->left)
                    q.push({node.first->left, 2 * node.second - 1});
                if (node.first->right)
                    q.push({node.first->right, 2 * node.second});
            }
            res = max(res, (int)(rightIndex - leftIndex + 1));
        }
        return res;
    }
};
// @lc code=end
