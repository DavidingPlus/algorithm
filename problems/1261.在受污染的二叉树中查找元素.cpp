/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
#include <unordered_map>

class FindElements {
public:
    // 用一个哈希表来存储树当中的值，为0表示不存在(默认)，为1表示存在
    unordered_map<int, int> hash;

    // 需要传入一个参数设定树根的初始值为0
    void traverse(TreeNode *root, int val) {
        if (nullptr == root)
            return;

        root->val = val;
        hash[root->val] = 1;

        traverse(root->left, 2 * val + 1);
        traverse(root->right, 2 * val + 2);
    }

    FindElements(TreeNode *root) {
        traverse(root, 0);
    }

    bool find(int target) {
        return 1 == hash[target];
    }
};

/**
 * Your FindElements object will be instantiated && called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end
