/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> ret;  // 结果数组
    string path;         // 维护遍历的实时状态

    void traverse(TreeNode *root) {
        if (!root)
            return;

        string val_str = to_string(root->val);

        if (!path.empty())
            path += "->";
        path += val_str;

        // 判断这个点是不是叶节点
        if (nullptr == root->left && nullptr == root->right)
            ret.push_back(path);

        traverse(root->left);
        traverse(root->right);

        for (int i = 0; i < val_str.size(); ++i)
            path.pop_back();  // 弹出这个数字
        if (!path.empty())
            for (int i = 0; i < 2; ++i)
                path.pop_back();  // 弹出"->"
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
