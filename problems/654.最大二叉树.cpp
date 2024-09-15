/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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

    TreeNode *constructMaximumBinaryTreeFromRange(const std::vector<int> &nums, int left, int right)
    {
        if (left > right) return nullptr;

        int pos = left;
        for (int i = left; i <= right; ++i)
        {
            if (nums[pos] < nums[i]) pos = i;
        }

        TreeNode *root = new TreeNode(nums[pos]);

        root->left = constructMaximumBinaryTreeFromRange(nums, left, pos - 1);
        root->right = constructMaximumBinaryTreeFromRange(nums, pos + 1, right);

        return root;
    }

    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) { return constructMaximumBinaryTreeFromRange(nums, 0, nums.size() - 1); }
};

// @lc code=end
