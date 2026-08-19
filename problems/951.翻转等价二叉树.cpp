/*
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
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
    bool ret = true;

    // 我们遍历二叉树1，遇到不对的就尽量进行翻转，如果翻转还是不对那么失败
    void traverse(TreeNode *root1, TreeNode *root1_father, TreeNode *root2) {
        if (nullptr == root1 && nullptr == root2)
            return;

        // 如果root1和root2二者不同时为空或者root1的值和root2的值不相同则表明遍历不相同
        if ((nullptr == root1 || nullptr == root2) ||
            root1->val != root2->val) {
            // TODO
        }

        traverse(root1->left, root1, root2->left);
        traverse(root1->right, root1, root2->right);
    }

    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        traverse(root1, nullptr, root2);

        return ret;
    }
};
// @lc code=end
