/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

/**
 * 遍历的思路
 **/
class Solution {
public:
    // 定义：找到 original 中 target 节点在 cloned 树中对应的节点
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;
        traverse(original, cloned);
        return res;
    }

private:
    TreeNode* target;
    TreeNode* res;
    // 二叉树遍历函数
    void traverse(TreeNode* original, TreeNode* cloned) {
        if (original == nullptr || res != nullptr) {
            return;
        }
        if (original == target) {
            res = cloned;
            return;
        }
        // 二叉树遍历框架
        traverse(original->left, cloned->left);
        traverse(original->right, cloned->right);
    }
};

/**
 * 分解问题的思路
 **/
class Solution2 {
public:
    // 定义：找到 original 中 target 节点在 cloned 树中对应的节点
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        }
        // 找到目标节点
        if (target == original) {
            return cloned;
        }
        // 去左子树找
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left != nullptr) {
            return left;
        }
        // 左子树找不到的话去右子树找
        return getTargetCopy(original->right, cloned->right, target);
    }
};

// @lc code=end
