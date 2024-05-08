/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
#include <vector>

class Solution {
public:
    vector<int> ret;
    int i = 0;  // 维护一个指针指向voyage的访问位置
    bool flag = true;

    // 我维护一个这个结点的父节点，用来进行交换的操作
    void traverse(TreeNode *root, vector<int> &voyage, TreeNode *father) {
        if (nullptr == root || !flag)
            return;

        if (voyage[i++] != root->val) {
            bool is_left = (root == father->left);

            // 尝试进行交换
            swap_child(father);
            if (is_left)
                root = father->left;
            else
                root = father->right;

            // 如果交换后，把root结点换成空了，或者值仍然不匹配，则失败
            if (nullptr == root || voyage[i - 1] != root->val) {
                flag = false;
                return;
            }

            // 加入交换结点
            ret.push_back(father->val);
        }

        traverse(root->left, voyage, root);
        traverse(root->right, voyage, root);
    }

    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        // 在前序遍历过程中，当我遇到一个顺序不符合voyage的时候，该怎么办？
        // 我们想，一个结点最多就两个子树，那么我这个节点的下一个遍历的位置肯定只有左右子树两种情况
        // 所以我尝试翻转这个根节点，如果翻转之后当前仍不能匹配，那么肯定无解，如此递归

        // 特判：如果根节点就不符合那根本不可能
        if (root->val != voyage[0])
            return {-1};

        traverse(root, voyage, nullptr);

        if (flag)
            return ret;
        else
            return {-1};
    }

    void swap_child(TreeNode *node) {
        auto tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
};
// @lc code=end
