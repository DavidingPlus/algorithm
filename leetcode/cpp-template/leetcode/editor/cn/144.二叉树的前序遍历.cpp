/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

    // 用一个全局变量来维护返回的值。
    std::vector<int> res;

    std::vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root) return {};

        res.emplace_back(root->val);

        // std::vector<T> 没有比较好的 append 另一个 vector 的方式，硬要做只能像下面那样，这一点也不优雅。对于 std::vector<T> 来说，追加另一个 vector 的元素不可能做到真正的 O(1)，因为它必须保持连续内存，至少要处理被追加的 n 个元素，复杂度是 O(n)。
        // std::vector<int> vec{1, 2}, vec2{3, 4, 5};
        // vec.reserve(vec.size() + vec2.size());
        // vec.insert(vec.end(), vec2.begin(), vec2.end());

        preorderTraversal(root->left);
        preorderTraversal(root->right);


        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
