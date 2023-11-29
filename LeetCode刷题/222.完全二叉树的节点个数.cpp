/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
#include <cmath>

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (nullptr == root)
            return 0;

        // 满二叉树的左右子树高度是相等的，所以一直往左和一直往右会获得相同的值
        // 但是如果是一个完全二叉树而不是满二叉树的话，则不然，但是我们发现完全二叉树的左右子树有一个特点，至少有一边的子树是满二叉树。因此我在这一边获得左右子树的高度能够立即得出个数
        // 所以我们需要在下面先计算高度来看是不是满二叉树，这样其实也对时间复杂对进行了优化
        // 计算左子树的高度
        int leftHight = 1;
        TreeNode *p = root;
        while (p->left) {
            ++leftHight;
            p = p->left;
        }

        // 计算右子树的高度
        int rightHight = 1;
        p = root;
        while (p->right) {
            ++rightHight;
            p = p->right;
        }

        if (leftHight == rightHight)
            return pow(2, leftHight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end
