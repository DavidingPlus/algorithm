/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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

    // 解法 1：递归遍历（BST 优化版本）
    TreeNode *res = nullptr;

    void traverse(TreeNode *root, int val)
    {
        if (!root) return;

        if (val == root->val)
        {
            res = root;

            return;
        }

        root->val > val ? traverse(root->left, val) : traverse(root->right, val);
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        traverse(root, val);

        return res;
    }


    // 解法 2：分解为自相似的子问题
    // TreeNode *searchBST(TreeNode *root, int val)
    // {
    //     if (!root) return nullptr;

    //     if (val == root->val) return root;

    //     return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    // }
};

// @lc code=end
