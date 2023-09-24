/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
 */

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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
public:
    int ret = 0;
    int count = 0;                 // 记录当前路径当中奇数元素的个数
    unordered_map<int, int> hash;  // 用哈希表来存储数值和个数的映射

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        ++hash[root->val];  // 增加节点值的出现次数
        // 如果出现次数为偶数，表示该节点在路径上出现了偶数次，可以从路径中移除
        // 注意等号优先级高于&运算！！！
        if (0 == (hash[root->val] & 1))
            --count;
        else
            ++count;

        if (nullptr == root->left && nullptr == root->right)
            // 当前节点是叶子节点，检查是否满足伪回文串条件
            if (count <= 1)
                ++ret;

        // 继续遍历左右子树
        traverse(root->left);
        traverse(root->right);

        // 回溯：恢复状态
        --hash[root->val];
        if (0 == (hash[root->val] & 1))
            --count;
        else
            ++count;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
