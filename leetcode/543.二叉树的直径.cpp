/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode *root) {
        // 过每个节点的最长直径就是左子树的高度加上右子树的高度
        // 遍历所有的节点获得最大值即可
        depth(root);
        return res;
    }

    int res = 0;

    int depth(TreeNode *root) {
        if (nullptr == root)
            return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        // 如果我这里改为后序遍历，我就能够在下面获得函数的返回值，进而在一次遍历的时候就能够获得过该节点的最大直径
        // 这个思路算是遍历加上划分为子问题合起来吧...
        res = max(res, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }
};
// @lc code=end
