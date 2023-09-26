/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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

class Solution {
public:
    // 方法1：遍历二叉树
    int ret = 0;  // 维护答案

    void traverse(TreeNode *root, int low, int high) {
        if (nullptr == root)
            return;

        if (low <= root->val && root->val <= high)
            ret += root->val;

        // 如果根节点的值小于等于low，那么没必要去左边遍历了
        if (root->val > low)
            traverse(root->left, low, high);
        if (root->val < high)
            traverse(root->right, low, high);
    }

    int rangeSumBST(TreeNode *root, int low, int high) {
        traverse(root, low, high);

        return ret;
    }

    // 方法2：大问题分解为小问题
    // int rangeSumBST(TreeNode *root, int low, int high) {
    //     if (nullptr == root)
    //         return 0;

    //     int ret = 0;
    //     if (low <= root->val && root->val <= high)
    //         ret += root->val;
    //     if (root->val > low)
    //         ret += rangeSumBST(root->left, low, high);
    //     if (root->val < high)
    //         ret += rangeSumBST(root->right, low, high);

    //     return ret;
    // }
};
// @lc code=end
