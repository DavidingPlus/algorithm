/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

#include "_treenode.h"


// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <bits/stdc++.h>


class Solution
{

public:

    // 解法 1：遍历一次 N 叉树
    int depth = 0; // 用 depth 变量维护到该结点位置的深度
    int res = 0;   // 记录最大深度

    void traverse(Node *root)
    {
        if (!root) return;

        ++depth;

        if (root->children.empty()) res = std::max(res, depth);

        for (auto &child : root->children) traverse(child);

        --depth;
    }

    int maxDepth(Node *root)
    {
        traverse(root);

        return res;
    }


    // 解法 2：划分为自相似的子问题
    // int maxDepth(Node *root)
    // {
    //     if (!root) return 0;

    //     int res = 0;

    //     for (auto &child : root->children) res = std::max(res, maxDepth(child));

    //     return 1 + res;
    // }


    // 解法 3：层序遍历，另一种遍历思路
    int maxDepth(Node *root)
    {
        if (!root) return 0;

        std::queue<Node *> q;
        q.push(root);

        int res = 0;

        while (!q.empty())
        {
            ++res;

            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front();
                q.pop();

                for (auto &child : node->children) q.push(child);
            }
        }

        return res;
    }
};

// @lc code=end
