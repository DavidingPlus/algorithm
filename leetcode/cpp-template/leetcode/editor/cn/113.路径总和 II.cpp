/*
 * @lc app=leetcode.cn id=113 lang=cpp
 * @lcpr version=30404
 *
 * [113] 路径总和 II
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

    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        traverse(root, targetSum);
        return res;
    }

    void traverse(TreeNode *root, const int &targetSum)
    {
        if (!root) return;

        sum += root->val, path.emplace_back(root->val);

        if (!root->left && !root->right && targetSum == sum) res.emplace_back(path);

        traverse(root->left, targetSum), traverse(root->right, targetSum);

        sum -= root->val, path.pop_back();
    }


    std::vector<std::vector<int>> res;

    std::vector<int> path;

    int sum = 0;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */
