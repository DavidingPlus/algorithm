/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // 第一种思路：遍历一次二叉树
    // int depth = 0;
    // int ret = __INT_MAX__;

    // void traverse(TreeNode* root) {
    //     if (!root)
    //         return;

    //     ++depth;
    //     // 这里多了一个限定条件，就是需要是叶节点
    //     if (!root->left && !root->right)
    //         ret = min(ret, depth);

    //     traverse(root->left);
    //     traverse(root->right);

    //     --depth;
    // }
    // int minDepth(TreeNode* root) {
    //     // 这里需要特判为空的话ret就不会被修改了
    //     if (!root)
    //         return 0;

    //     traverse(root);
    //     return ret;
    // }

    // 第二种思路：将大问题分解为小问题
    int minDepth(TreeNode *root) {
    }
};
// @lc code=end
