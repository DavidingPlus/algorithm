/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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

class Solution {
public:
    int maxLevelSum(TreeNode *root) {
        // 题目的意思是找层数之和最大的那个，然后如果有相同的就返回层数最小的那个
        if (!root)
            return 0;

        pair<int, int> depth_sum;  // 存储返回值的层数和元素之和
        depth_sum.first = 1;
        depth_sum.second = root->val;

        queue<TreeNode *> q;
        q.push(root);

        int depth = 1;  // 维护实时层数

        while (!q.empty()) {
            int sz = q.size();

            int sum = 0;  // 维护元素之和

            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                sum += cur->val;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }

            // 进行比较
            if (depth_sum.second < sum) {
                depth_sum.first = depth;
                depth_sum.second = sum;
            }
            // 这里不用判断相同的情况，因为后面遍历的层数比前面的大

            ++depth;
        }

        return depth_sum.first;
    }
};
// @lc code=end
