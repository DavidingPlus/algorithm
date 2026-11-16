/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

    // // 解法 1：递归遍历。
    // bool hasPathSum(TreeNode *root, int targetSum)
    // {
    //     traverse(root, targetSum);
    //     return flag;
    // }

    // void traverse(TreeNode *root, const int &targetSum)
    // {
    //     if (!root) return;

    //     sum += root->val;

    //     if (!root->left && !root->right && targetSum == sum)
    //     {
    //         flag = true;
    //         return;
    //     }

    //     traverse(root->left, targetSum), traverse(root->right, targetSum);

    //     sum -= root->val;
    // }


    // int sum = 0;

    // bool flag = false;


    // 解法 2：分解为自相似的子问题。
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 以叶子节点为递归出口，因此 !root 为空的情况肯定不是叶子节点触发的，所以均返回 false。因为对叶子节点触发的 !root，从逻辑上可以作为递归出口判断。
        if (!root) return false;
        if (!root->left && !root->right) return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
