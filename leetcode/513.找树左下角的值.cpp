/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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

    // 解法 1：递归遍历，由于是前序遍历，因此第一次访问到的一定就是当前层最左边的那个
    // int depth = 0;
    // std::pair<int, int> res = {0, 0}; // 记录某层最左边元素的层数和值

    // void traverse(TreeNode *root)
    // {
    //     if (!root) return;

    //     ++depth;

    //     // 这样设计和判断条件，保证了进入下一层前序遍历访问最左边的元素的时候就能更新 res，同时同层的遍历不会对其造成影响
    //     if (depth > res.first) res = {depth, root->val};

    //     traverse(root->left);
    //     traverse(root->right);

    //     --depth;
    // }

    // int findBottomLeftValue(TreeNode *root)
    // {
    //     traverse(root);

    //     return res.second;
    // }

    // 解法 2：层序遍历
    int findBottomLeftValue(TreeNode *root)
    {
        if (!root) return 0;

        std::queue<TreeNode *> q;
        q.push(root);

        int res = 0;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front();
                q.pop();

                if (0 == i) res = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};

// @lc code=end
