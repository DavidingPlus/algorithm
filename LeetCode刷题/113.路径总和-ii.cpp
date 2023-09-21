/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>

class Solution {
public:
    pair<vector<int>, int> path_sum;  // 维护遍历时候的路径和相加的值
    vector<vector<int>> ret;          // 结果数组

    void traverse(TreeNode *root, int targetSum) {
        if (!root)
            return;

        // 到达新结点，压入结点
        path_sum.first.push_back(root->val);
        path_sum.second += path_sum.first.back();
        // 判断是否满足条件
        if (targetSum == path_sum.second && !root->left && !root->right)
            ret.push_back(path_sum.first);

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        // 回退，弹出结点
        path_sum.second -= path_sum.first.back();
        path_sum.first.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        traverse(root, targetSum);
        return ret;
    }
};
// @lc code=end
