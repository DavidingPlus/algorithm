/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    // TreeNode* res = new TreeNode(-1);  // 虚拟头结点
    // TreeNode* p = res;                 // 工作指针

    // void traverse(TreeNode* root) {
    //     if (nullptr == root)
    //         return;

    //     p->right = new TreeNode(root->val);
    //     p = p->right;

    //     traverse(root->left);
    //     traverse(root->right);
    // }

    // // 法1：遍历一次二叉树，构造一棵新树
    // void flatten(TreeNode* root) {
    //     if (nullptr == root)
    //         return;

    //     traverse(root);
    //     // 不能直接赋值，因为形参，没办法改变
    //     root->left = nullptr;
    //     root->right = res->right->right;
    // }

    // 法2：自相似的子问题
    void flatten(TreeNode* root) {
        if (nullptr == root)
            return;

        flatten(root->left);
        flatten(root->right);

        // 先拉直，在合并
        if (root->left) {
            TreeNode* p = root->left;

            while (p->right)
                p = p->right;

            p->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
// @lc code=end
