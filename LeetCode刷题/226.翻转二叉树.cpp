/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    // 我们还是写一个traverse函数，在原树上操作，这是第一种思路
    void traverse(TreeNode *root) {
        if (!root)
            return;

        // 到达本结点之后，把本结点的左右结点交换，然后递归
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        traverse(root->left);
        traverse(root->right);
    }

    TreeNode *invertTree(TreeNode *root) {
        traverse(root);
        return root;
    }

    // 我们生成一颗新树，这是第二种思路
    //  TreeNode *invertTree(TreeNode *root) {
    //      if (!root)
    //          return nullptr;

    //     TreeNode *newroot = new TreeNode(root->val);

    //     // 将原来的树从右边然后到左边开始遍历，新树从左边接上就好了
    //     newroot->left = invertTree(root->right);
    //     newroot->right = invertTree(root->left);

    //     return newroot;
    // }
};
// @lc code=end
