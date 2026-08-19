/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode *increasingBST(TreeNode *root) {
        if (nullptr == root)
            return nullptr;

        auto leftChild = increasingBST(root->left);
        auto rightChild = increasingBST(root->right);

        // 如果left为空，那么只管right
        if (nullptr == leftChild) {
            root->right = rightChild;
            return root;
        }

        // 找到left的最右下节点
        auto p = leftChild;
        while (p->right) p = p->right;

        p->right = root;
        root->left = nullptr;
        root->right = rightChild;
        return leftChild;
    }
};
// @lc code=end
