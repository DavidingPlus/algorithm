/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

    // 解法 1：递归遍历
    int sum = 0;
    bool flag = false;

    void traverse(TreeNode *root, int targetSum)
    {
        if (!root) return;

        sum += root->val;

        if (!root->left && !root->right && targetSum == sum)
        {
            flag = true;
            return;
        }

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        sum -= root->val;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        traverse(root, targetSum);

        return flag;
    }


    // 方法2：分解为自相似的子问题
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root) return false;
        if (!root->left && !root->right) return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

// @lc code=end
