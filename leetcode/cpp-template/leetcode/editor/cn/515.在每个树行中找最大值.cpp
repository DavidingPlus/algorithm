/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

struct TreeNode {
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

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Solution {
public:
    // 方法1：层序遍历
    // vector<int> largestValues(TreeNode *root) {
    //     if (nullptr == root)
    //         return {};

    //     vector<int> res;
    //     queue<TreeNode *> q;
    //     q.push(root);

    //     while (false == q.empty()) {
    //         int n = q.size();
    //         int maxValue = -__INT_MAX__ - 1;

    //         for (int i = 0; i < n; ++i) {
    //             auto node = q.front();
    //             q.pop();

    //             maxValue = std::max(maxValue, node->val);

    //             if (node->left)
    //                 q.push(node->left);
    //             if (node->right)
    //                 q.push(node->right);
    //         }
    //         res.push_back(maxValue);
    //     }
    //     return res;
    // }

    // 方法2：递归遍历
    int depth = -1;
    vector<int> res;

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        ++depth;
        if (depth == res.size())  // 不可能出现大于的情况，因为在大于之前就已经插入扩容了
            res.push_back(root->val);
        else
            res[depth] = std::max(res[depth], root->val);

        traverse(root->left);
        traverse(root->right);

        --depth;
    }

    vector<int> largestValues(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end
