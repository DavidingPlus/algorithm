/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
#include <string>

class Solution {
public:
    string res, path;

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        path.insert(path.begin(), 'a' + root->val);
        if (nullptr == root->left and nullptr == root->right)
            res = min(res, path);

        traverse(root->left);
        traverse(root->right);

        path.erase(path.begin());
    }

    string smallestFromLeaf(TreeNode *root) {
        // 初始化res，给一个比z大的
        res.push_back('z' + 1);
        traverse(root);
        return res;
    }
};
// @lc code=end
