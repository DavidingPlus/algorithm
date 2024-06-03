/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
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

class Solution {
public:
    // 方法1：遍历二叉树
    // bool flag = false;
    // int sum = 0;

    // void traverse(TreeNode *root, int targetSum) {
    //     if (nullptr == root)
    //         return;

    //     sum += root->val;
    //     if (nullptr == root->left && nullptr == root->right && targetSum == sum) {
    //         flag = true;
    //         return;
    //     }

    //     traverse(root->left, targetSum);
    //     traverse(root->right, targetSum);

    //     sum -= root->val;
    // }

    // bool hasPathSum(TreeNode *root, int targetSum) {
    //     traverse(root, targetSum);
    //     return flag;
    // }

    // 方法2：分解问题
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (nullptr == root)
            return false;

        if (targetSum == root->val && nullptr == root->left && nullptr == root->right)
            return true;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end
