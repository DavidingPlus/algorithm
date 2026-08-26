/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    // 思路同 106 题。
    TreeNode *buildTreeFromRange(std::vector<int> &preorder, int preorderLeft, int preorderRight, std::vector<int> &inorder, int inorderLeft, int inorderRight)
    {
        if (preorderLeft > preorderRight) return nullptr;

        int rootPosInorder = 0;
        for (int i = inorderLeft; i <= inorderRight; ++i)
        {
            if (preorder[preorderLeft] == inorder[i])
            {
                rootPosInorder = i;
                break;
            }
        }

        TreeNode *root = new TreeNode(preorder[preorderLeft]);
        root->left = buildTreeFromRange(preorder, 1 + preorderLeft, (1 + preorderLeft) + (rootPosInorder - inorderLeft) - 1, inorder, inorderLeft, rootPosInorder - 1);
        root->right = buildTreeFromRange(preorder, (1 + preorderLeft) + (rootPosInorder - inorderLeft), preorderRight, inorder, 1 + rootPosInorder, inorderRight);


        return root;
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) { return buildTreeFromRange(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1); }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
