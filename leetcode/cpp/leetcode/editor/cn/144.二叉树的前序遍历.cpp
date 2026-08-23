/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

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
class Solution {
public:
    std::vector<int> ret;  // 用一个全局变量来维护返回的值

    std::vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return {};

        ret.push_back(root->val);

        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return ret;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
