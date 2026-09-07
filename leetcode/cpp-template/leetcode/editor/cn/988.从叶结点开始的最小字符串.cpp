/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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

class Solution
{

public:

    std::string res = {'a' + 26}, path;


    void traverse(TreeNode *root)
    {
        if (!root) return;

        path += 'a' + root->val;

        if (!root->left && !root->right)
        {
            // 题目要求叶子到根，所以比较时反向构造字符串。
            std::string rev(path.rbegin(), path.rend());
            res = std::min(res, rev);
        }

        traverse(root->left);
        traverse(root->right);

        path.pop_back();
    }

    std::string smallestFromLeaf(TreeNode *root)
    {
        traverse(root);
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
