/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30404
 *
 * [437] 路径总和 III
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

    // 本题思路同 560 题。

    // 版本 1：原封不动将 560 题的板子搬过来。
    // int pathSum(TreeNode *root, int targetSum)
    // {
    //     if (!root) return 0;

    //     preSum.reserve(N);
    //     preSum.emplace_back(0);

    //     // 不要忘了初始化这个。
    //     um[0] = 1;

    //     traverse(root, targetSum);


    //     return res;
    // }

    // void traverse(TreeNode *root, const int &targetSum)
    // {
    //     if (!root) return;

    //     preSum.emplace_back(preSum.back() + root->val);

    //     if (um.count(preSum.back() - targetSum)) res += um[preSum.back() - targetSum];

    //     ++um[preSum.back()];

    //     traverse(root->left, targetSum);
    //     traverse(root->right, targetSum);

    //     --um[preSum.back()];

    //     preSum.pop_back();
    // }


    // static constexpr int N = 10 + 1000;

    // int res = 0;

    // // Node.val 的数量级是 10 的 9 次方，前缀和可能超出 int 上限，开 long long。
    // std::vector<long long> preSum;

    // std::unordered_map<long long, int> um;


    // 版本 2：空间复杂度优化版本。留意到版本 1 的 preSum 在遍历过程中只用得到 preSum.back()，因此只需要维护一个 long long 存储当前的路径总和即可。
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root) return 0;

        um[0] = 1;

        traverse(root, targetSum);


        return res;
    }

    void traverse(TreeNode *root, const int &targetSum)
    {
        if (!root) return;

        curPathSum += root->val;

        if (um.count(curPathSum - targetSum)) res += um[curPathSum - targetSum];

        ++um[curPathSum];

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        --um[curPathSum];

        curPathSum -= root->val;
    }


    int res = 0;

    long long curPathSum = 0;

    std::unordered_map<long long, int> um;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
