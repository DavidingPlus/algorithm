/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generateTrees(int n) {
        // 这个题的思路和前面是一样的，都是针对不用值的根节点分左右，然后递归构造
        // 只不过这里的左右子树是一个列表，需要弄完之后一一把可能的BST都构造出来
        return build(1, n);
    }

    vector<TreeNode *> build(int left, int right) {
        vector<TreeNode *> res;

        // 大于表示子树为空，代表返回空指针
        if (left > right) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = left; i <= right; ++i) {
            auto lefts = build(left, i - 1);
            auto rights = build(i + 1, right);

            // 然后一一构造
            for (auto &leftChild : lefts)
                for (auto &rightChild : rights) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftChild;
                    root->right = rightChild;

                    res.push_back(root);
                }
        }

        return res;
    }
};
// @lc code=end
