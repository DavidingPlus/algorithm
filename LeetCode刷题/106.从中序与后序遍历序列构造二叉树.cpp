/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }

        int rootValue = postorder.back();
        TreeNode* root = new TreeNode(rootValue);

        auto rootPos = find(inorder.begin(), inorder.end(), rootValue);
        int leftSize = rootPos - inorder.begin();

        vector<int> leftInorder(inorder.begin(), rootPos);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftSize);
        vector<int> rightInorder(rootPos + 1, inorder.end());
        vector<int> rightPostorder(postorder.begin() + leftSize, postorder.end() - 1);

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
// @lc code=end
