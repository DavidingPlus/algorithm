/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // TreeNode *res = nullptr;

    // // 方法1：BST自带的优化过后的遍历
    // void traverse(TreeNode *root, int val) {
    //     if (nullptr == root)
    //         // 没找到
    //         return;

    //     if (val == root->val) {
    //         res = root;
    //         return;
    //     }
    //     if (root->val > val)
    //         traverse(root->left, val);
    //     if (root->val < val)
    //         traverse(root->right, val);
    // }

    // TreeNode *searchBST(TreeNode *root, int val) {
    //     traverse(root, val);
    //     return res;
    // }

    // 方法2：分解为自相似的子问题
    TreeNode *searchBST(TreeNode *root, int val) {
        if (nullptr == root)
            return nullptr;

        if (val == root->val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);

        return nullptr;
    }
};
// @lc code=end
