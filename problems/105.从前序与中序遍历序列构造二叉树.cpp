/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include "_treenode.h"


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

#include <bits/stdc++.h>


class Solution
{

public:

    // 思路同 106 题
    TreeNode *buildTreeFromRange(std::vector<int> &preorder, int preorderLeft, int preorderRight, std::vector<int> &inorder, int inorderLeft, int inorderRight)
    {
        if (preorderLeft > preorderRight) return nullptr;

        TreeNode *root = new TreeNode(preorder[preorderLeft]);

        int pos = 0;
        for (; inorder[inorderLeft + pos] != root->val; ++pos)
            ;

        root->left = buildTreeFromRange(preorder, preorderLeft + 1, preorderLeft + pos, inorder, inorderLeft, inorderLeft + pos - 1);
        root->right = buildTreeFromRange(preorder, preorderLeft + pos + 1, preorderRight, inorder, inorderLeft + pos + 1, inorderRight);

        return root;
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) { return buildTreeFromRange(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1); }
};

// @lc code=end
