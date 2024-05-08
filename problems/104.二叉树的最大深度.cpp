/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // 定义两个外部变量
    // int res = 0;    // res就是最大深度的返回值
    // int depth = 0;  // depth变量维护当前节点的深度

    // // 解法1：通过遍历解决，思考三个时间结点应该做的事情
    // void traverse(TreeNode *root) {
    //     if (nullptr == root)
    //         return;

    //     ++depth;
    //     res = max(res, depth);
    //     traverse(root->left);
    //     traverse(root->right);
    //     --depth;
    // }

    // int maxDepth(TreeNode *root) {
    //     traverse(root);
    //     return res;
    // }

    // 解法2：动态规划问题的祖宗，划分为自相似的子问题
    int maxDepth(TreeNode *root) {
        if (nullptr == root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// @lc code=end
