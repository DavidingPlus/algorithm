/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

class Solution {
public:
    // 定义两个外部变量
    int res = 0;    // res就是最大深度的返回值
    int depth = 0;  // depth变量维护当前节点的深度

    // 解法1：通过遍历解决，思考三个时间结点应该做的事情
    void traverse(TreeNode *root) {
        if (!root)
            return;

        // 前序遍历位置
        ++depth;                // 进入到当前结点，深度加1
        res = max(res, depth);  // 当前结点有可能是最大的深度
        traverse(root->left);
        // 中序遍历位置
        traverse(root->right);
        // 后序遍历位置
        --depth;  // 当前节点以下的子树遍历完毕，往上回退，深度减1
    }

    int maxDepth(TreeNode *root) {
        traverse(root);
        return res;
    }

    // 解法2：动态规划问题的祖宗
    //  int maxDepth(TreeNode *root) {
    //      if (!root)
    //          return 0;

    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }
};
// @lc code=end
