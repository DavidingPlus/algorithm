/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    void traverse(TreeNode *root, int &count, int &val, int k) {
        if (nullptr == root)
            return;

        traverse(root->left, count, val, k);
        // 中序位置
        ++count;
        if (count == k) {
            val = root->val;
            return;
        }

        traverse(root->right, count, val, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        // 二叉搜索树的中序遍历是有序的
        int count = 0;
        int res = 0;

        traverse(root, count, res, k);

        return res;
    }
};
// @lc code=end
