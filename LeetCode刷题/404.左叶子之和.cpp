/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sum = 0;

    void traverse(TreeNode *root) {
        if (!root)
            return;

        // 我需要判断这个节点的左子节点是不是叶节点
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;

        traverse(root->left);
        traverse(root->right);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        traverse(root);
        return sum;
    }
};
// @lc code=end
