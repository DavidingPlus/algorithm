/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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

    int countNodes(TreeNode *root)
    {
        // 满二叉树的左右子树高度是相等的，所以一直往左和一直往右会获得相同的值
        // 但是如果是一个完全二叉树而不是满二叉树的话，则不然，但是我们发现完全二叉树的左右子树有一个特点，就是只有最后一层可能没有被填满。在这样的情况下，左子树的高度是必然大于等于右子树的，小于就不满足完全二叉树的性质了，因为是从左往右填的。如果左子树的高度等于右子树，那么左子树一定是一颗满二叉树，能通过高度直接计算出个数，右子树利用自相似的子问题递归即可。如果左子树的高度大于右子树，那么右子树一定是满二叉树，同理即可。

        if (!root) return 0;

        int leftHight = 0;
        for (auto pMove = root->left; pMove; pMove = pMove->left) ++leftHight;

        int rightHight = 0;
        for (auto pMove = root->right; pMove; pMove = pMove->left) ++rightHight;

        // leftHight >= rightHight，不可能小于
        return leftHight > rightHight
                   ? 1 + (1 << rightHight) - 1 + countNodes(root->left)
                   : 1 + (1 << leftHight) - 1 + countNodes(root->right);
    }
};

// @lc code=end
