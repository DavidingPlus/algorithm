/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
#include <vector>

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums, int left, int right) {
        // 取闭区间
        if (left > right)
            return nullptr;

        // 找到最大值的下标
        int maxIndex = left;
        for (int i = left; i <= right; ++i)
            maxIndex = nums[i] > nums[maxIndex] ? i : maxIndex;

        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = constructMaximumBinaryTree(nums, left, maxIndex - 1);
        root->right = constructMaximumBinaryTree(nums, maxIndex + 1, right);

        return root;
    }
};
// @lc code=end
