/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

    std::vector<std::string> res;

    std::string path;


    void traverse(TreeNode *root)
    {
        if (!root) return;

        // 记录进入当前节点之前 path 的长度，后面回溯时直接恢复到这个长度。
        int oldSize = path.size();

        path += std::to_string(root->val);
        if (!root->left && !root->right) res.emplace_back(path);
        path += "->";

        traverse(root->left), traverse(root->right);

        path.resize(oldSize);
    }

    std::vector<std::string> binaryTreePaths(TreeNode *root)
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
