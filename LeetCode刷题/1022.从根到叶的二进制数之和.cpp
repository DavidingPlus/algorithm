/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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

class Solution {
public:
    int ret = 0;
    int sum = 0;  // 维护实时状态值

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // 我们如何把10变为101，10 << 1 | 1
        // 注意位运算!
        sum = (sum << 1) | root->val;
        if (nullptr == root->left && nullptr == root->right)
            ret += sum;

        traverse(root->left);
        traverse(root->right);

        sum = sum >> 1;
    }

    int sumRootToLeaf(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
