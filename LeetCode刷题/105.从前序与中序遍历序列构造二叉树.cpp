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
        int n = preorder.size();
        if (0 == n)
            return nullptr;
        // 按照递归的思维一步一步走就好了
        // 找到根节点在inorder中的位置
        int rootIndex = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        // 构造根节点
        auto root = new TreeNode(preorder[0]);

        // 构造新的preorder和inorder
        auto newLeftPreorder = std::vector<int>{preorder.begin() + 1, preorder.begin() + 1 + rootIndex};
        auto newRightPreorder = std::vector<int>{preorder.begin() + 1 + rootIndex, preorder.end()};
        auto newLeftInorder = std::vector<int>{inorder.begin(), inorder.begin() + rootIndex};
        auto newRightInorder = std::vector<int>{inorder.begin() + rootIndex + 1, inorder.end()};

        // 连接
        root->left = buildTree(newLeftPreorder, newLeftInorder);
        root->right = buildTree(newRightPreorder, newRightInorder);
        return root;
    }
};
// @lc code=end
