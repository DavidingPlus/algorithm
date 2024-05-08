/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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

class Solution {
public:
    // 方法1：遍历，进行序列化
    void traverse(TreeNode *root, string &str) {
        if (nullptr == root) {
            str += "#,";
            return;
        }

        str += std::to_string(root->val) + ",";

        traverse(root->left, str);
        traverse(root->right, str);
    }

    string serialize(TreeNode *root) {
        string res;
        traverse(root, res);
        return res;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        return serialize(p) == serialize(q);
    }

    // 方法2：分解子问题
    // bool isSameTree(TreeNode *p, TreeNode *q) {
    //     if (nullptr == p and nullptr == q)
    //         return true;

    //     else if (nullptr == p or nullptr == q)
    //         return false;

    //     return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    // }
};
// @lc code=end
