/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30404
 *
 * [337] 打家劫舍 III
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

    int rob(TreeNode *root)
    {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];

        int res = 0;
        // 分为偷 root 和不偷 root 两种情况。
        res = std::max(res,
                       root->val +
                           (root->left ? rob(root->left->left) + rob(root->left->right) : 0) +
                           (root->right ? rob(root->right->left) + rob(root->right->right) : 0));

        res = std::max(res, rob(root->left) + rob(root->right));

        memo[root] = res;


        return res;
    }


    // 增加备忘录 memo。
    std::unordered_map<TreeNode *, int> memo;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
