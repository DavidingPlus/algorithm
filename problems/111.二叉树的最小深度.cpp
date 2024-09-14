/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

    // 解法 1：递归遍历
    int depth = 0, res = INT_MAX;

    void traverse(TreeNode *root)
    {
        if (!root) return;

        ++depth;

        if (!root->left && !root->right) res = std::min(res, depth);

        traverse(root->left);
        traverse(root->right);

        --depth;
    }

    int minDepth(TreeNode *root)
    {
        traverse(root);

        return res != INT_MAX ? res : 0; // 特判空树
    }


    // 解法 2：将问题分解为自相似的子问题
    // int minDepth(TreeNode *root)
    // {
    //     if (!root) return 0;

    //     // 这里要考虑一个细节，深度必须要是叶子节点。因此如果一个结点的某一边是空的，按理来讲那一边会输出 0，但是他不能参与计算（上面对空树的判断对整个逻辑是适用的，但是对这里的递归就不适用了）。因此这时候这个结点的最小深度完全依赖于另一边的递归结果
    //     // 因此对于某一个节点就有四种情况进行讨论
    //     if (!root->left && !root->right)
    //     {
    //         return 1;
    //     }
    //     else if (!root->left) // 走到这里左右子节点都不可能为空，因此这样简单写就代表仅存在右子树的情况，下面同理
    //     {
    //         return 1 + minDepth(root->right);
    //     }
    //     else if (!root->right)
    //     {
    //         return 1 + minDepth(root->left);
    //     }
    //     else
    //     {
    //         return 1 + std::min(minDepth(root->left), minDepth(root->right));
    //     }
    // }


    // 解法 3：层次遍历，在广度搜索的情况下如果遇到叶节点，那么就是最小的深度
    // 我们比较一下深度优先和广度优先，广度优先的优势在于，求最小的问题的时候一般可以不用把整个结构遍历完，比如这里就是遍历一部分就得出答案了，在这里效率会比深度优先会快很多！
    // int minDepth(TreeNode *root)
    // {
    //     if (!root) return 0;

    //     std::queue<TreeNode *> q;
    //     q.push(root);

    //     int depth = 0;

    //     while (!q.empty())
    //     {
    //         ++depth;

    //         int n = q.size();
    //         for (int i = 0; i < n; ++i)
    //         {
    //             auto node = q.front();
    //             q.pop();

    //             if (!node->left && !node->right) return depth;

    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);
    //         }
    //     }

    //     // 这一步包走不到的，占位
    //     return -1;
    // }
};

// @lc code=end
