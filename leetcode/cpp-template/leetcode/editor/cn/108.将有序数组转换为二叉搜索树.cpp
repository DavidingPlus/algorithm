/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30404
 *
 * [108] 将有序数组转换为二叉搜索树
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

    TreeNode *sortedArrayToBST(vector<int> &nums) { return build(nums, 0, nums.size() - 1); }

    TreeNode *build(const std::vector<int> &nums, int left, int right)
    {
        if (left > right) return nullptr;

        // 按照升序排列的数组，就是二叉搜索树的中序遍历结果，结合平衡条件，根节点就取数组的中点。
        int mid = left + (right - left) / 2;

        return new TreeNode(nums[mid],
                            build(nums, left, mid - 1),
                            build(nums, 1 + mid, right));
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */
