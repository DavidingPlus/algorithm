/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool flag = true;

    // 计算每个节点的左右子树的高度差的绝对值
    // 这个函数是计算树的最大高度的，我们的目的在这里面进行修改
    int maxDepth(TreeNode *root) {
        if (nullptr == root)
            return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // 在后序的地方进行判断
        if (std::abs(leftHeight - rightHeight) > 1)
            flag = false;

        return 1 + std::max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root) {
        maxDepth(root);
        return flag;
    }
};
// @lc code=end
