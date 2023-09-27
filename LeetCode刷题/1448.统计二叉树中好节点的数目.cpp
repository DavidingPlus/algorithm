/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int ret = 0;
    int Max = -__INT_MAX__ - 1;  // 我们维护序列当中的最大值

    // 好节点的意思转化一下就是：遍历新加入的值必须大于等于原先序列中的最大值
    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        int pre = Max;  // 用一个变量记录现在的Max，等会儿回退的时候需要用到
        if (root->val >= Max) {
            Max = root->val;
            ++ret;
        }

        traverse(root->left);
        traverse(root->right);

        Max = pre;
    }

    int goodNodes(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
