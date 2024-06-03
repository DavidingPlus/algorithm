/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
#include <queue>

class Solution {
public:
    int res = 0;

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        if (root->left && nullptr == root->left->left && nullptr == root->left->right)
            res += root->left->val;

        // 左叶子的含义是有父节点并且左右子树为空
        traverse(root->left);
        traverse(root->right);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end
