/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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

    // // 虚拟头结点。
    // TreeNode *res = new TreeNode(-1);
    // // 工作指针。
    // TreeNode *p = res;

    // void traverse(TreeNode *root)
    // {
    //     if (!root) return;

    //     p->right = new TreeNode(root->val);
    //     p = p->right;

    //     traverse(root->left);
    //     traverse(root->right);
    // }

    // // 法 1：遍历一次二叉树，构造一棵新树。
    // void flatten(TreeNode *root)
    // {
    //     if (!root) return;

    //     traverse(root);

    //     // 不能直接赋值，因为形参，没办法改变。
    //     root->left = nullptr;
    //     root->right = res->right->right;
    // }


    // 法 2：自相似的子问题。
    void flatten(TreeNode *root)
    {
        if (!root) return;

        // 先拉直，在合并。
        flatten(root->left);
        flatten(root->right);

        // 找到左子树的叶子结点，与右子树连接起来。如果左子树为空，无需额外处理。
        TreeNode *p = root->left;
        if (p)
        {
            while (p->right) p = p->right;

            p->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
