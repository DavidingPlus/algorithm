/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // 第一种思路：遍历一次二叉树
    // int depth = 0;
    // int ret = __INT_MAX__;

    // void traverse(TreeNode* root) {
    //     if (!root)
    //         return;

    //     ++depth;
    //     // 这里多了一个限定条件，就是需要是叶节点
    //     if (!root->left && !root->right)
    //         ret = min(ret, depth);

    //     traverse(root->left);
    //     traverse(root->right);

    //     --depth;
    // }
    // int minDepth(TreeNode* root) {
    //     // 这里需要特判为空的话ret就不会被修改了
    //     if (!root)
    //         return 0;

    //     traverse(root);
    //     return ret;
    // }

    // 第二种思路：将大问题分解为小问题
    // int minDepth(TreeNode *root) {
    //     // 我们下面已经把除了root为空的情况都已经考虑到了，所以这里可以特判
    //     if (!root)
    //         return 0;

    //     if (!root->left && !root->right)
    //         return 1;

    //     // 对于子树为空指针的情况，我们不予计算
    //     if (!root->left)
    //         return 1 + minDepth(root->right);
    //     if (!root->right)
    //         return 1 + minDepth(root->left);
    //     else
    //         return 1 + min(minDepth(root->left), minDepth(root->right));
    // }

    // 第三种思路：层次遍历，在广度搜索的情况下如果遇到叶节点，那么就是最小的深度
    // 我们比较一下深度优先和广度优先，广度优先的优势在于，求最小的问题的时候一般可以不用把整个结构遍历完，比如这里就是遍历一部分就得出答案了，在这里效率会比深度优先会快很多!!
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;

        int layer = 1;  // 记录层数
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();

                // 如果遇到叶结点那么就是最小深度
                if (!cur->left && !cur->right)
                    return layer;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
            ++layer;  // 将层次++
        }
        return layer;
    }
};
// @lc code=end
