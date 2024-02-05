/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    string path;

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // 加入到path中
        path += std::to_string(root->val) + "->";
        // 判断是不是叶子节点
        if (nullptr == root->left and nullptr == root->right) {
            auto str = path;
            for (int i = 0; i < 2; ++i) str.pop_back();
            res.push_back(str);
        }

        traverse(root->left);
        traverse(root->right);

        // 删除对应数字的->和数符
        for (int i = 0; i < 2 + std::to_string(root->val).size(); ++i)
            path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end
