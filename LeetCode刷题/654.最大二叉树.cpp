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
        return buildBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode *buildBinaryTree(const vector<int> &nums, int left, int right) {
        // 这里我们取闭区间
        if (left > right)
            return nullptr;

        // 查询left到right中的最大值
        int maxIndex = left;
        for (int i = left; i <= right; ++i)
            // nums不重复
            if (nums[maxIndex] < nums[i])
                maxIndex = i;

        // 创建根节点
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = buildBinaryTree(nums, left, maxIndex - 1);
        root->right = buildBinaryTree(nums, maxIndex + 1, right);

        return root;
    }
};
// @lc code=end
