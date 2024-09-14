/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

    // 判断 p 和 q 两棵树是不是轴对称的
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }


    bool isSymmetric(TreeNode *root)
    {
        // 这个题目用遍历不是很好写，思路清晰，但是要同时递归两个不太好，所以还是分解子问题

        if (!root) return true;

        return isMirror(root->left, root->right);
    }
};

// @lc code=end
