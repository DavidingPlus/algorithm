/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
#include <vector>

class Solution {
public:
    // 方法1：用层序遍历来解决
    // vector<int> rightSideView(TreeNode *root) {
    //     if (nullptr == root)
    //         return {};

    //     queue<TreeNode *> q;
    //     vector<int> res;
    //     // 根节点入队
    //     q.push(root);
    //     while (false == q.empty()) {
    //         // 记录此刻这层当中的元素个数，因为后续会变化
    //         int n = q.size();
    //         for (int i = 0; i < n; ++i) {
    //             auto node = q.front();
    //             q.pop();

    //             if (n - 1 == i)
    //                 res.push_back(node->val);

    //             if (node->left)
    //                 q.push(node->left);
    //             if (node->right)
    //                 q.push(node->right);
    //         }
    //     }
    //     return res;
    // }

    // 方法2：通过遍历二叉树解决问题
    vector<int> res;
    vector<int> ref;  // 参考数组，用作检测每一层是否已经访问过
    int depth = 0;

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        ++depth;
        if (666 == ref[depth]) {
            res.push_back(root->val);
            ref[depth] = -1;
        }

        // 右视图，那肯定先遍历右边，每一层最先看到的节点就是右侧的值
        traverse(root->right);
        traverse(root->left);

        --depth;
    }

    vector<int> rightSideView(TreeNode *root) {
        // 初始化ref
        ref.resize(100 + 10);
        std::fill(ref.begin(), ref.end(), 666);

        traverse(root);
        return res;
    }
};
// @lc code=end
