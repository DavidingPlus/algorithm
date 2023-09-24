/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        // 我们就遍历一次tree1，然后在上面添加root2的结点
        if (!root1 && !root2)
            return nullptr;

        if (!root1)
            // 把tree2上的结点给接上去，因为可能root1这部分没有的结构root2是很大一坨，所以不能先创建结点
            // 并且链接成功之后，root2下面的分支不会被继续遍历了，因为本来就不属于root1，会返回这个结点给上层进行链接，这就是这道题前序遍历的逻辑
            return root2;
        if (!root2)
            return root1;

        // 如果重叠的话，相加并且继续递归
        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
// @lc code=end
