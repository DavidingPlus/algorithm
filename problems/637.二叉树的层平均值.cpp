/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root) {
        if (!root)
            return {};

        vector<double> ret;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;
            int count = 0;

            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();

                ++count;
                sum += (double)cur->val;

                // 将左右子树入队列
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
            ret.push_back(sum / count);
        }

        return ret;
    }
};
// @lc code=end
