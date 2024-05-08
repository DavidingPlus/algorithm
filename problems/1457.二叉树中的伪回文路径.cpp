/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
#include <unordered_map>

class Solution {
public:
    int oddNum = 0;  // 维护遍历过程中路径的实时奇数个数
    int res = 0;
    unordered_map<int, int> um;  // 需要用哈希表记录实时的元素和个数关系，方便更新oddNum

    void traverse(TreeNode *root) {
        if (nullptr == root)
            return;

        // 伪回文路径的条件是路径中值的个数只有一个为奇数或者全为偶数，换句话说，奇数的个数<=1
        um[root->val]++ & 1 ? --oddNum : ++oddNum;  // 不存在的也包含在这里面了，不存在会直接创建，赋初值0

        // 叶节点
        if (nullptr == root->left and nullptr == root->right and oddNum <= 1)
            ++res;

        traverse(root->left);
        traverse(root->right);

        um[root->val]-- & 1 ? --oddNum : ++oddNum;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end
