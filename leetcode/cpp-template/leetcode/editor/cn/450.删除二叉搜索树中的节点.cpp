/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

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


class Solution
{

public:

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root) return nullptr;

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        // 找到了，删除。
        else
        {
            // 1. 如果左右子树都为空，直接删除该结点。
            if (!root->left && !root->right) return nullptr;
            // 2. 排除情况 1 后，左子树或者右子树为空，返回不空的那个子树。
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // 3. 左右子树都不为空。为了不破坏 BST 的性质，必须找到左子树中最大的那个节点，或者右子树中最小的那个节点来接替自己。这里选择左子树最大的结点。
            TreeNode *leftMax = getMax(root->left);

            root->val = leftMax->val;
            root->left = deleteNode(root->left, leftMax->val);
        }


        return root;
    }

    TreeNode *getMax(TreeNode *root)
    {
        TreeNode *res = root;
        while (res->right) res = res->right;
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
