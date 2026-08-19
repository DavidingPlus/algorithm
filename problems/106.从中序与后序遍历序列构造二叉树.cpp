/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

    // 为了防止在递归中每次创建 std::vector 浪费资源，给出 left 和 right 写一个版本
    TreeNode *buildTreeFromRange(std::vector<int> &inorder, int inorderLeft, int inorderRight, std::vector<int> &postorder, int postorderLeft, int postorderRight)
    {
        // 在递归的过程中，中序遍历和后序遍历的数组的大小时时刻刻是一样的，因此判断条件只需要写一个即可
        if (inorderLeft > inorderRight) return nullptr;

        TreeNode *root = new TreeNode(postorder[postorderRight]);

        // pos 的基准值是 inorderLeft，因此注意坐标的换算
        int pos = 0;
        for (; root->val != inorder[inorderLeft + pos]; ++pos)
            ;

        root->left = buildTreeFromRange(inorder, inorderLeft, inorderLeft + pos - 1, postorder, postorderLeft, postorderLeft + pos - 1);
        root->right = buildTreeFromRange(inorder, inorderLeft + pos + 1, inorderRight, postorder, postorderLeft + pos, postorderRight - 1);

        return root;
    }

    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) { return buildTreeFromRange(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1); }
};

// @lc code=end
