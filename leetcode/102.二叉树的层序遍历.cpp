/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // 这是用纯正的层次遍历来实现
    // vector<vector<int>> levelOrder(TreeNode *root) {
    //     if (!root)
    //         return {};

    //     vector<vector<int>> ret;

    //     // 层次遍历，对应的是bfs广度优先算法，我们需要用到的是队列
    //     queue<TreeNode *> q;
    //     // 将根节点入队列
    //     q.push(root);

    //     while (!q.empty()) {
    //         // 一次while循环对应一层while的遍历，就是拿取这一层的结点遍历，然后把他们的子节点插入队列
    //         int sz = q.size();  // for循环会改变q.size()，所以存储
    //         vector<int> layer;
    //         for (int i = 0; i < sz; ++i) {
    //             auto cur = q.front();

    //             layer.push_back(cur->val);

    //             // 将左右子树入队列
    //             if (cur->left)
    //                 q.push(cur->left);
    //             if (cur->right)
    //                 q.push(cur->right);

    //             q.pop();
    //         }
    //         ret.push_back(layer);
    //     }

    //     return ret;
    // }

    // 我们用递归遍历来实现一下
    int depth = 0;  // 维护一下递归遍历的高度，来看一下是哪一层
    vector<vector<int>> ret;

    void traverse(TreeNode *root) {
        if (!root)
            return;

        // 进入到这个结点的时候，判断是哪一层，然后加入到对应的位置
        ++depth;
        // 越界只可能越一个界
        // 注意0号对应的是第一层
        if (ret.size() == depth - 1)
            ret.push_back({root->val});
        else
            ret[depth - 1].push_back(root->val);

        traverse(root->left);
        traverse(root->right);

        --depth;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        traverse(root);

        return ret;
    }
};
// @lc code=end
