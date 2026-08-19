/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int res = 0, num = 0;  // res维护最终结果，num维护过程中实时的值

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        num = 10 * num + root->val;
        if (nullptr == root->left && nullptr == root->right)
            res += num;

        traverse(root->left);
        traverse(root->right);

        num /= 10;
    }

    int sumNumbers(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end
