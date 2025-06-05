/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
#include <queue>

class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        // root不为空
        queue<TreeNode *> q;
        q.push(root);
        int level = -1;  // 记录level

        while (false == q.empty()) {
            ++level;
            int n = q.size();
            int ref = level & 1 ? 1e6 + 10 : 1 - 10;  // val的范围在1到1e6之间

            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                // 奇数层，为奇数数或者不满足严格递减失败
                if (level & 1) {
                    if (node->val & 1 || node->val >= ref)
                        return false;
                }

                // 偶数层，与上面相反
                /**
                 * @note 遇到位运算记得加上括号，因为它的优先级低
                 */
                if (false == (level & 1)) {
                    if (false == (node->val & 1) || node->val <= ref)
                        return false;
                }

                ref = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return true;
    }
};
// @lc code=end
