/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

    std::vector<std::string> res;
    std::string path;

    void traverse(TreeNode *root)
    {
        if (!root) return;

        path += std::to_string(root->val) + "->";
        if (!root->left && !root->right) res.emplace_back(path.substr(0, path.size() - 2)); // 需要去掉末尾的 ->

        traverse(root->left);
        traverse(root->right);

        for (int i = 0; i < std::to_string(root->val).size() + 2; ++i) path.pop_back();
    }

    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        traverse(root);

        return res;
    }
};

// @lc code=end
