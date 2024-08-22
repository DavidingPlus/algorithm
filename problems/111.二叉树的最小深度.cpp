/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

    // 第一种思路：遍历一次二叉树
    // int depth = 0, res = INT_MAX;

    // void traverse(TreeNode *root)
    // {
    //     if (nullptr == root) return;

    //     ++depth;

    //     if (nullptr == root->left && nullptr == root->right)
    //     {
    //         res = std::min(res, depth);
    //     }

    //     traverse(root->left);
    //     traverse(root->right);

    //     --depth;
    // }

    // int minDepth(TreeNode *root)
    // {
    //     // 特判 leetcode 数据，空树 []
    //     if (nullptr == root) return 0;

    //     traverse(root);
    //     return res;
    // }


    // 第二种思路：将大问题分解为小问题
    // int minDepth(TreeNode *root)
    // {
    //     if (nullptr == root) return 0;

    //     // 这里要考虑一个细节，深度必须要是叶子节点。因此如果一个结点的某一边是空的，按理来讲那一边会输出 0，但是他不能参与计算（举个例子想想就明白了）。因此这时候这个结点的最小深度完全依赖于另一边的递归结果
    //     // 因此对于某一个节点就有四种情况进行讨论
    //     if (nullptr == root->left && nullptr == root->right)
    //     {
    //         return 1;
    //     }
    //     else if (nullptr == root->left)
    //     {
    //         return 1 + minDepth(root->right);
    //     }
    //     else if (nullptr == root->right)
    //     {
    //         return 1 + minDepth(root->left);
    //     }
    //     else
    //     {
    //         return 1 + std::min(minDepth(root->left), minDepth(root->right));
    //     }
    // }


    // 第三种思路：层次遍历，在广度搜索的情况下如果遇到叶节点，那么就是最小的深度
    // 我们比较一下深度优先和广度优先，广度优先的优势在于，求最小的问题的时候一般可以不用把整个结构遍历完，比如这里就是遍历一部分就得出答案了，在这里效率会比深度优先会快很多!!
    int minDepth(TreeNode *root)
    {
        if (nullptr == root) return 0;

        std::queue<TreeNode *> q;
        q.push(root);

        int depth = 0;

        while (false == q.empty())
        {
            ++depth;

            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front();

                if (nullptr == node->left && nullptr == node->right) return depth;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                q.pop();
            }
        }

        // 这一步包走不到的，占位
        return -1;
    }
};

// @lc code=end
