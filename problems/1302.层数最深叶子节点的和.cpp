/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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

class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        if (!root)
            return 0;

        int ret = 0;  // 我们不知道哪一层是最后一层，所以我们用层次遍历的方式维护每一层的和，这样下来结束的时候就是最后一层

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int sum = 0;
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();

                sum += cur->val;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
            ret = sum;
        }

        return ret;
    }
};
// @lc code=end
