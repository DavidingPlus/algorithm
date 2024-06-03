/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>

class Solution {
public:
    // 由于需要找出具体的路径，所以只能遍历来做了
    vector<vector<int>> res;
    int sum = 0;
    vector<int> path;

    void traverse(TreeNode *root, int targetSum) {
        if (nullptr == root)
            return;

        sum += root->val;
        path.push_back(root->val);
        if (nullptr == root->left && nullptr == root->right && targetSum == sum)
            res.push_back(path);

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        path.pop_back();
        sum -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        traverse(root, targetSum);
        return res;
    }
};
// @lc code=end
