/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
using namespace std;

class Solution {
public:
    int num = 0;        // 用num变量来维护从根节点到当前节点的路径的和
    bool flag = false;  // 用一个标志位记录

    void traverse(TreeNode *root, int targetSum) {
        if (!root) {
            return;
        }

        // 前序遍历位置，结点刚进来将值相加，并且判断是否为正确路径
        num += root->val;
        // 判断是否为符合条件的叶结点
        if (targetSum == num && !root->left && !root->right) {
            flag = true;
            return;
        }

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);
        // 后序遍历位置，该节点下面的子树访问完成，准备往上回退
        num -= root->val;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        traverse(root, targetSum);

        return flag;
    }
};
// @lc code=end
