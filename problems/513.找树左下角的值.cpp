/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
#include <queue>

class Solution {
public:
    int depth = 0;
    pair<int, int> val_depth = {0, 0};

    // 我用递归遍历实现这个题
    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        ++depth;
        // 这样递归下去，每次遇到新的一层都是这一层最左边的
        if (depth > val_depth.second)
            val_depth = {root->val, depth};

        traverse(root->left);
        traverse(root->right);

        --depth;
    }

    int findBottomLeftValue(TreeNode *root) {
        traverse(root);

        return val_depth.first;
    }

    // 用层次遍历实现这个题
    //  int findBottomLeftValue(TreeNode *root) {
    //      if (!root)
    //          return {};

    //     int ret;
    //     queue<TreeNode *> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         double sum = 0;
    //         int count = 0;

    //         int sz = q.size();
    //         for (int i = 0; i < sz; ++i) {
    //             auto cur = q.front();

    //             // 遍历完毕自然就是最下层
    //             if (0 == i)
    //                 ret = cur->val;

    //             // 将左右子树入队列
    //             if (cur->left)
    //                 q.push(cur->left);
    //             if (cur->right)
    //                 q.push(cur->right);

    //             q.pop();
    //         }
    //     }

    //     return ret;
    // }
};
// @lc code=end
