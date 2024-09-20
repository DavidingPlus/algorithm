/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

    int pre = -1, res = INT_MAX;

    void traverse(TreeNode *root)
    {
        // 同 98 题的思路，在中序遍历中维护结果

        if (!root) return;

        traverse(root->left);

        // 这个题结点的值没有负数，不用设置一个标志了
        if (-1 != pre) res = std::min(res, std::abs(root->val - pre));

        pre = root->val;

        traverse(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        traverse(root);

        return res;
    }
};

// @lc code=end
