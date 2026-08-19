/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

        for (auto& node : pp) cout << node->val << ' ';
        cout << endl;
        for (auto& node : qp) cout << node->val << ' ';
        cout << endl;

        // 从头开始比较
        int i = 0;
        while (1) {
            // 满足条件才能继续
            if (pp[i]->val == qp[i]->val and
                i < pp.size() - 1 && i < qp.size() - 1 && pp[i + 1] == qp[i + 1]) {
                ++i;
                continue;
            }
            break;
        }

        return pp[i];
    }

    // 二叉搜索树可以进行优化
    TreeNode* find(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (nullptr == root)
            return nullptr;

        path.push_back(root);

        if (target == root->val)
            return root;

        // 利用BST的特性
        if (root->val > target)
            return find(root->left, target, path);
        else if (root->val < target)
            return find(root->right, target, path);

        path.pop_back();

        return nullptr;
    }
};
// @lc code=end
