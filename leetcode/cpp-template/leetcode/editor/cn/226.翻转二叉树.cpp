/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

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

class Solution
{

public:

    // 解法 1：遍历二叉树，在过程中修改。
    // void traverse(TreeNode *root)
    // {
    //     if (!root) return;

    //     traverse(root->left), traverse(root->right);

    //     std::swap(root->left, root->right);
    // }

    // TreeNode *invertTree(TreeNode *root)
    // {
    //     traverse(root);
    //     return root;
    // }

    // 解法 2：把原问题分为自相似的子问题。
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root) return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        std::swap(root->left, root->right);


        return root;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
