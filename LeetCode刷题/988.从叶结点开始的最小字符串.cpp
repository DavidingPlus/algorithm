/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
#include <string>

class Solution {
public:
    string path;  // 维护遍历过程中的实时状态

    void traverse(TreeNode *root, string &ret) {
        if (nullptr == root)
            return;

        path.insert(path.begin(), root->val + 'a');
        if (nullptr == root->left && nullptr == root->right)
            ret = (path <= ret) ? path : ret;

        traverse(root->left, ret);
        traverse(root->right, ret);

        path.erase(path.begin());
    }

    string smallestFromLeaf(TreeNode *root) {
        string ret;      // 维护结果
        ret += 'z' + 1;  // 构造一个最大值

        traverse(root, ret);

        return ret;
    }
};
// @lc code=end
