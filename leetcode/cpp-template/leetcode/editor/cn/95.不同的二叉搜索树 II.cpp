/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=30404
 *
 * [95] 不同的二叉搜索树 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


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

    // 本题思路和 96 题完全一致。

    std::vector<TreeNode *> build(int left, int right)
    {
        std::vector<TreeNode *> res;

        if (left > right) return {nullptr};

        // 这里包含 left == right 的逻辑，也就是生成一个根节点。
        for (int i = left; i <= right; ++i)
        {
            std::vector<TreeNode *> leftTrees = build(left, i - 1),
                                    rightTrees = build(1 + i, right);

            // 给 root 节点穷举所有左右子树的组合。
            for (auto &leftTree : leftTrees)
            {
                for (auto &rightTree : rightTrees) res.emplace_back(new TreeNode(i, leftTree, rightTree));
            }
        }


        return res;
    }

    std::vector<TreeNode *> generateTrees(int n) { return build(1, n); }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
