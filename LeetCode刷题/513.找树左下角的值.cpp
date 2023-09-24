/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root) {
        if (!root)
            return {};

        int ret;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;
            int count = 0;

            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();

                // 遍历完毕自然就是最下层
                if (0 == i)
                    ret = cur->val;

                // 将左右子树入队列
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
        }

        return ret;
    }
};
// @lc code=end
