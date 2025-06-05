/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int res = 0, num = 0;  // res维护答案，num维护实时的十进制数字值

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        num = 2 * num + root->val;
        if (nullptr == root->left && nullptr == root->right)
            res += num;

        traverse(root->left);
        traverse(root->right);

        num /= 2;
    }

    int sumRootToLeaf(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end
