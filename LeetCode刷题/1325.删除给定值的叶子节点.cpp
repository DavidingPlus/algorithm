/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 *
 * [1325] 删除给定值的叶子节点
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
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        // 这就是一个典型的递归修改数据结构的例子
        if (!root)
            return nullptr;

        // 递归遍历左右子树，如果满足条件的返回null，然后更新root的左右子树，就代表删除了
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // 判断该节点是不是满足要求的叶节点
        // 注意，一定要放在后续遍历的位置，这样我才能直到这个结点遍历完毕的时候是不是叶节点，才能满足题目条件
        if (!root->left && !root->right && target == root->val)
            return nullptr;

        return root;
    }
};
// @lc code=end
