/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

    int sum = 0;


    void traverse(TreeNode *root)
    {
        if (!root) return;

        // 按照中序从右子树开始遍历，遍历完根节点的时候，sum 的值就是答案。
        traverse(root->right);

        sum += root->val;
        root->val = sum;

        traverse(root->left);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        traverse(root);
        return root;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
