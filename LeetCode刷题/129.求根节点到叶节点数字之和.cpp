/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int ret = 0;  // 维护返回结果
    string str;   // 维护实时的遍历情况

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // val在0到9之间
        str += to_string(root->val);
        if (nullptr == root->left && nullptr == root->right)
            ret += atoi(str.c_str());

        traverse(root->left);
        traverse(root->right);

        str.pop_back();
    }

    int sumNumbers(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
