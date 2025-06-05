/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

#include "_treenode.h"


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

#include <bits/stdc++.h>


class Solution
{

public:

    int res = 0;

    void traverse(TreeNode *root)
    {
        if (!root) return;

        if (root->left && !root->left->left && !root->left->right) res += root->left->val;

        traverse(root->left);
        traverse(root->right);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        traverse(root);

        return res;
    }
};

// @lc code=end
