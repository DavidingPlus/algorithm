/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    // 每一层，那么我们肯定第一想到的是层次遍历
    // vector<int> largestValues(TreeNode *root) {
    //     if (!root)
    //         return {};

    //     vector<int> ret;

    //     queue<TreeNode *> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         int _max = -__INT_MAX__ - 1;

    //         int sz = q.size();

    //         for (int i = 0; i < sz; ++i) {
    //             auto cur = q.front();

    //             _max = max(cur->val, _max);

    //             // 将左右子树入队列
    //             if (cur->left)
    //                 q.push(cur->left);
    //             if (cur->right)
    //                 q.push(cur->right);

    //             q.pop();
    //         }
    //         ret.push_back(_max);
    //     }

    //     return ret;
    // }

    // 但是我们用递归遍历的思路来做
    int depth = 0;  // 维护层数
    vector<int> ret;

    void traverse(TreeNode *root) {
        if (!root)
            return;

        ++depth;
        if (ret.size() == depth - 1)
            ret.push_back({root->val});
        else
            ret[depth - 1] = max(ret[depth - 1], root->val);

        traverse(root->left);
        traverse(root->right);

        --depth;
    }

    vector<int> largestValues(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
