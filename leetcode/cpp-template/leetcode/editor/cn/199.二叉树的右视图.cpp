/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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

    // 解法 1：层序遍历。
    // std::vector<int> rightSideView(TreeNode *root)
    // {
    //     std::vector<int> res;
    //     if (!root) return res;

    //     std::queue<TreeNode *> q;
    //     q.push(root);

    //     while (!q.empty())
    //     {
    //         int n = q.size();
    //         for (int i = 0; i < n; ++i)
    //         {
    //             auto node = q.front();
    //             q.pop();

    //             if (0 == i) res.emplace_back(node->val);

    //             // 右视图应该从右边开始遍历。
    //             if (node->right) q.push(node->right);
    //             if (node->left) q.push(node->left);
    //         }
    //     }


    //     return res;
    // }

    // 解法 2：遍历二叉树。
    std::vector<int> res;

    int depth = -1;

    void traverse(TreeNode *root)
    {
        if (!root) return;

        ++depth;

        // 根据 depth 和 res.size() 来判断是否是当前层遍历的第一个结点。
        if (depth == res.size()) res.emplace_back(root->val);

        // 右视图应该从右边开始遍历。
        traverse(root->right), traverse(root->left);

        --depth;
    }

    std::vector<int> rightSideView(TreeNode *root)
    {
        traverse(root);
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
