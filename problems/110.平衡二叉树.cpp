/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

    bool flag = true;

    // 求一棵树的最大高度的函数，在这个函数中做文章
    int getHeight(TreeNode *root)
    {
        if (!root) return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        if (std::abs(left - right) > 1)
        {
            flag = false;

            return -1; // 目的已达成，为了节省运行时间，直接返回
        }

        return 1 + std::max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        getHeight(root);

        return flag;
    }
};

// @lc code=end
