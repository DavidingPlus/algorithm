/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <algorithm>
#include <vector>

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // preorder和inorder的个数是同步的
        if (preorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder.front());
        // 找到根节点在inorder中的位置
        auto root_pos = find(inorder.begin(), inorder.end(), root->val);
        // 左右子树的前序遍历
        vector<int> left_preorder = vector<int>{preorder.begin() + 1, preorder.begin() + 1 + (root_pos - inorder.begin())};
        vector<int> right_preorder = vector<int>{preorder.begin() + 1 + (root_pos - inorder.begin()), preorder.end()};
        // 左右子树的中序遍历
        vector<int> left_inorder = vector<int>{inorder.begin(), root_pos};
        vector<int> right_inorder = vector<int>{root_pos + 1, inorder.end()};

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};
// @lc code=end
