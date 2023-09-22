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
    // 第一种方法：通过遍历一次二叉树

    // int sum = 0;        // 用sum变量来维护从根节点到当前节点的路径的和
    // bool flag = false;  // 用一个标志位记录

    // void traverse(TreeNode *root, int targetSum) {
    //     if (!root) {
    //         return;
    //     }

    //     // 前序遍历位置，结点刚进来将值相加，并且判断是否为正确路径
    //     sum += root->val;
    //     // 判断是否为符合条件的叶结点
    //     if (targetSum == sum && !root->left && !root->right) {
    //         flag = true;
    //         return;
    //     }

    //     traverse(root->left, targetSum);
    //     traverse(root->right, targetSum);
    //     // 后序遍历位置，该节点下面的子树访问完成，准备往上回退
    //     sum -= root->val;
    // }

    // bool hasPathSum(TreeNode *root, int targetSum) {
    //     traverse(root, targetSum);

    //     return flag;
    // }

    // 第二种思路；通过分解问题
    // 这里就是既然你让我找一条路径，那我就去找子树当中是否包含target-num的路径
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root)
            return false;

        // 如果走到了叶节点，那么需要判断
        if (!root->left && !root->right)
            return root->val == targetSum;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end
