/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int ret = 0;

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // 一个结点对应着一个祖父结点，那么相反；一个祖父结点也有对应的孙子结点，左右子树都可能有，一共四种情况
        if (0 == (root->val & 1)) {
            // 为了防止内存泄漏，我们判断子节点和孙子节点
            if (root->left && root->left->left)
                ret += root->left->left->val;
            if (root->left && root->left->right)
                ret += root->left->right->val;
            if (root->right && root->right->left)
                ret += root->right->left->val;
            if (root->right && root->right->right)
                ret += root->right->right->val;
        }

        traverse(root->left);
        traverse(root->right);
    }

    int sumEvenGrandparent(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
