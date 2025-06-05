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
    int res = -1;

    void traverse(TreeNode *root, int &num, int k) {
        if (nullptr == root)
            return;

        traverse(root->left, num, k);

        ++num;
        if (num == k) {
            res = root->val;
            return;
        }

        traverse(root->right, num, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        // 二叉搜索树的中序遍历是有序的
        int num = 0;

        traverse(root, num, k);
        return res;
    }
};
// @lc code=end
