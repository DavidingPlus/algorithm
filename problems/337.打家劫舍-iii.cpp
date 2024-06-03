/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

struct TreeNode
{
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

#include <bits/stdc++.h>

class Solution
{
public:
    // memo ，存储已经计算好的结果
    std::unordered_map<TreeNode *, int> memo;

    // 用递归加 memo 的思路来做
    int rob(TreeNode *root)
    {
        if (nullptr == root)
            return 0;

        if (memo.end() == memo.find(root))
        {
            // rob() 函数的含义是，偷取以 root 为根节点的二叉树能偷到的最大值，因此可以分为根节点偷取以及根节点不偷取
            // 不偷取 root
            int res1 = rob(root->left) + rob(root->right);
            // 偷取 root
            auto leftLeft = root->left && root->left->left ? root->left->left : nullptr;
            auto leftRight = root->left && root->left->right ? root->left->right : nullptr;
            auto rightLeft = root->right && root->right->left ? root->right->left : nullptr;
            auto rightRight = root->right && root->right->right ? root->right->right : nullptr;
            int res2 = root->val + rob(leftLeft) + rob(leftRight) + rob(rightLeft) + rob(rightRight);

            memo[root] = std::max(res1, res2);
        }

        return memo[root];
    }
};
// @lc code=end
