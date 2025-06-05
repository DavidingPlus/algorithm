/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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

    // 解法 1：遍历，进行序列化
    void traverse(TreeNode *root, std::string &s)
    {
        if (!root)
        {
            s += "#,";
            return;
        }

        s += std::to_string(root->val) + ',';

        traverse(root->left, s);
        traverse(root->right, s);
    }

    std::string serialize(TreeNode *root)
    {
        std::string res;
        traverse(root, res);

        res.pop_back(); // 去掉末尾的 ','

        return res;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) { return serialize(p) == serialize(q); }


    // 解法 2：分解子问题
    // bool isSameTree(TreeNode *p, TreeNode *q)
    // {
    //     if (!p && !q) return true;
    //     if (!p || !q) return false;

    //     return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // }
};

// @lc code=end
