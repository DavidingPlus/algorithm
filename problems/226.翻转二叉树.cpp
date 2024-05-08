/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    // 遍历一次，在原地修改
    // void traverse(TreeNode *root) {
    //     if (nullptr == root)
    //         return;

    //     // 到达本节点后将左右子树进行交换，当然交换的是指针，所以需要后续的遍历交换
    //     TreeNode *tmp = root->left;
    //     root->left = root->right;
    //     root->right = tmp;

    //     traverse(root->left);
    //     traverse(root->right);
    // }

    // TreeNode *invertTree(TreeNode *root) {
    //     traverse(root);
    //     return root;
    // }

    // 把原问题分为自相似的子问题
    TreeNode *invertTree(TreeNode *root) {
        if (nullptr == root)
            return nullptr;

        // root左子树被改了，需要临时存储
        TreeNode *tmp = root->left;

        root->left = invertTree(root->right);
        root->right = invertTree(tmp);

        return root;
    }
};
// @lc code=end
