/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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

    // 需要求出路径，因此只能使用遍历的做法
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    int sum = 0;

    void traverse(TreeNode *root, int targetSum)
    {
        if (!root) return;

        path.emplace_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && targetSum == sum) res.emplace_back(path);

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        sum -= root->val;
        path.pop_back();
    }

    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        traverse(root, targetSum);

        return res;
    }
};

// @lc code=end
