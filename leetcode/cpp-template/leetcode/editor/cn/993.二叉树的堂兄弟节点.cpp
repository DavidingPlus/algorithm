/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    bool is_x_visited = false, is_y_visited = false;
    int depth = -1;
    vector<pair<int, TreeNode *>> info;  // 记录两个结点的相关信息

    // 我们在遍历的过程中存储父节点
    void traverse(TreeNode *root, TreeNode *father, int x, int y) {
        if (nullptr == root)
            return;

        ++depth;

        // 如果遇到目标值，进行存储
        if (!is_x_visited && x == root->val) {
            is_x_visited = true;
            info.push_back({depth, father});
        }
        if (!is_y_visited && y == root->val) {
            is_y_visited = true;
            info.push_back({depth, father});
        }

        traverse(root->left, root, x, y);
        traverse(root->right, root, x, y);

        --depth;
    }

    bool isCousins(TreeNode *root, int x, int y) {
        traverse(root, nullptr, x, y);

        return info[0].first == info[1].first &&
               info[0].second != info[1].second;
    }
};
// @lc code=end
