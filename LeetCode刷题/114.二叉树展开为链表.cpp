/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
using namespace std;

class Solution {
public:
    // 第二种思路
    void flatten(TreeNode *root) {
        if (!root)
            return;

        // 把左右子树递归拉平
        flatten(root->left);
        flatten(root->right);

        // 最后处理本结点
        auto left = root->left;
        auto right = root->right;

        root->left = nullptr;
        root->right = left;

        auto move = root;
        while (move->right)
            move = move->right;

        move->right = right;
    }
};
// @lc code=end
