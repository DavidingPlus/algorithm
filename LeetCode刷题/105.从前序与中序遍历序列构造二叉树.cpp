/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <algorithm>
#include <vector>

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())
            return nullptr;

        size_t inRootPos = find(inorder.begin(), inorder.end(), preorder.front()) - inorder.begin();

        // 构造root
        TreeNode *root = new TreeNode(preorder.front());

        // 左子树
        auto newLeftPreorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + inRootPos);
        auto newLeftInorder = vector<int>(inorder.begin(), inorder.begin() + inRootPos);
        // 右子树
        auto newRightPreorder = vector<int>(preorder.begin() + 1 + inRootPos, preorder.end());
        auto newRightInorder = vector<int>(inorder.begin() + inRootPos + 1, inorder.end());

        root->left = buildTree(newLeftPreorder, newLeftInorder);
        root->right = buildTree(newRightPreorder, newRightInorder);

        return root;
    }
};
// @lc code=end
