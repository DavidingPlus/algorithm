/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // 判断输入的两棵树是不是镜像对称的
    bool Check(TreeNode *tree1, TreeNode *tree2) {
        if (nullptr == tree1 && nullptr == tree2)
            return true;

        // 都为空除去之后就是一个为空一个不为空
        if (nullptr == tree1 || nullptr == tree2)
            return false;

        // 剩下的情况就是都不为空
        if (tree1->val != tree2->val)
            return false;

        // 我们判断tree1的左子树和tree2的右子树相同，另一方同理即可，这样一直下去就是镜像对称的
        return Check(tree1->left, tree2->right) &&
               Check(tree1->right, tree2->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (nullptr == root)
            return true;

        return Check(root->left, root->right);
    }
};
// @lc code=end
