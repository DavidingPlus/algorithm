/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

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


class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode *root) {
        if (!root)
            return {};

        std::vector<double> ret;

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;
            int count = 0;

            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();

                ++count;
                sum += (double)cur->val;

                // 将左右子树入队列
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                q.pop();
            }
            ret.push_back(sum / count);
        }

        return ret;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
