/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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

    // res 维护答案，num 维护实时的十进制数字值。
    int res = 0, num = 0;


    void traverse(TreeNode *root)
    {
        if (!root) return;

        num = 2 * num + root->val;

        if (!root->left && !root->right) res += num;

        traverse(root->left), traverse(root->right);

        num /= 2;
    }

    int sumRootToLeaf(TreeNode *root)
    {
        traverse(root);
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
