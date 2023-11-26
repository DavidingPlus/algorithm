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
    int sum = 0;

    void traverse(TreeNode *root) {
        // 先遍历右边，然后进行中序遍历，到达该节点的时候维护的和刚好就是条件
        // 并且遇到的节点值都比现在的小，所以sum也不需要考虑出去的时候需要减掉

        if (nullptr == root)
            return;

        traverse(root->right);

        sum += root->val;
        root->val = sum;

        traverse(root->left);
    }

    TreeNode *convertBST(TreeNode *root) {
        traverse(root);
        return root;
    }
};
// @lc code=end
