/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Solution {
public:
    // 方法1：用层次遍历来解决
    // vector<int> rightSideView(TreeNode *root) {
    //     if (!root)
    //         return {};

    //     vector<int> ret;
    //     queue<TreeNode *> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         int sz = q.size();
    //         for (int i = 0; i < sz; ++i) {
    //             auto cur = q.front();

    //             if (sz - 1 == i)
    //                 ret.push_back(cur->val);

    //             if (cur->left)
    //                 q.push(cur->left);

    //             if (cur->right)
    //                 q.push(cur->right);

    //             q.pop();
    //         }
    //     }
    //     return ret;
    // }

    // 方法2：用深度优先，递归方法来解决
    vector<int> ret;
    int depth = 0;  // 维护深度

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // 从右边看，那肯定是从先遍历右边
        // 每一层出现的第一个值就是可以看见的
        ++depth;
        if (depth - 1 == ret.size())
            ret.push_back(root->val);

        traverse(root->right);
        traverse(root->left);

        --depth;
    }

    vector<int> rightSideView(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
