/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pp, qp;

        // 拿到路径
        find(root, p->val, pp);
        find(root, q->val, qp);

        // 从头开始比较
        int i = 0;
        while (1) {
            // 满足条件才能继续
            if (pp[i]->val == qp[i]->val and
                i < pp.size() - 1 and i < qp.size() - 1 and pp[i + 1] == qp[i + 1]) {
                ++i;
                continue;
            }
            break;
        }

        return pp[i];
    }

    // 遍历找到某个节点，然后得到路径
    // 将问题转化为子问题和遍历相加的思路。。。
    TreeNode* find(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (nullptr == root)
            return nullptr;

        path.push_back(root);

        if (target == root->val)
            return root;

        // 这个函数需要一个返回值，如果为真代表在左边找到了，不需要去右边了
        TreeNode* leftRes = find(root->left, target, path);
        if (leftRes)
            return leftRes;

        TreeNode* rightRes = find(root->right, target, path);
        if (rightRes)
            return rightRes;

        path.pop_back();

        return nullptr;
    }
};
// @lc code=end
