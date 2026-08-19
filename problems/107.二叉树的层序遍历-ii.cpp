/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
#include <queue>
#include <vector>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // 思路是一样的，只不过每次插入的时候插入到头部
        if (!root)
            return {};

        vector<vector<int>> ret;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> layer;

            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                layer.push_back(cur->val);

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
            // 这里需要从头部插入
            ret.insert(ret.begin(), layer);
        }

        return ret;
    }
};
// @lc code=end
