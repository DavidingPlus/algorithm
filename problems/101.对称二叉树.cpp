/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // 这个题目用遍历不是很好写，思路清晰，但是要同时递归两个不太好，所以还是分解子问题
    bool isMirror(TreeNode *p, TreeNode *q) {
        if (nullptr == p and nullptr == q)
            return true;
        else if (nullptr == p or nullptr == q)
            return false;

        return p->val == q->val and isMirror(p->left, q->right) and isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root) {
        return isMirror(root->left, root->right);
    }
};
// @lc code=end
