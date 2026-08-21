/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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

class Solution {
public:
    // 方法1：遍历二叉树
    // 这个题的技巧的是中序遍历是有序的，因此在遍历过程中我们能确定大致的返回，节省一下时间
    // int res = 0;

    // void traverse(TreeNode *root, int low, int high) {
    //     if (nullptr == root)
    //         return;

    //     traverse(root->left, low, high);

    //     if (root->val >= low && root->val <= high)
    //         res += root->val;
    //     else if (root->val > high)
    //         return;

    //     traverse(root->right, low, high);
    // }

    // int rangeSumBST(TreeNode *root, int low, int high) {
    //     traverse(root, low, high);
    //     return res;
    // }

    // 方法2：分解子问题
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (nullptr == root)
            return 0;

        // 值得注意的是如果当前节点不满足条件，并不代表这颗自述的其他节点也不满足条件
        if (root->val < low)  // 当前节点和左子树不满足
            return rangeSumBST(root->right, low, high);
        else if (root->val > high)
            return rangeSumBST(root->left, low, high);
        else
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
// @lc code=end
