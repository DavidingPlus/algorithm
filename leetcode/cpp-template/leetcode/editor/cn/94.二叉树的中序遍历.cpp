/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

    std::vector<int> inorderTraversal(TreeNode *root)
    {
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root)
    {
        if (!root) return;

        traverse(root->left);
        res.emplace_back(root->val);
        traverse(root->right);
    }


    std::vector<int> res;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
