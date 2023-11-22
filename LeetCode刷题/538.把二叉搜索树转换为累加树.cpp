/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

class Solution {
public:
    int sum = 0;  // 维护相加和

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // 为什么先遍历右子树
        // 我们需要获得这个树的降序，然后拿到大于等于这个数的所有值，所以需要从右向左来
        traverse(root->right);

        sum += root->val;
        root->val = sum;

        traverse(root->left);
    }

    TreeNode *convertBST(TreeNode *root) {
        // 我们可以先遍历一遍拿到总和，但是没必要，从右边向左遍历就可以了
        traverse(root);
        return root;
    }
};
// @lc code=end
