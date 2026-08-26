/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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

    // 由于需要递归调用，为了防止普遍的数组拷贝，提供一个根据范围构造的函数。（左闭右闭）
    TreeNode *constructMaximumBinaryTreeRange(std::vector<int> &nums, int left, int right)
    {
        if (left > right) return nullptr;

        // 找到 nums Range 范围中最大的元素。
        int pos = left;
        for (int i = left; i <= right; ++i)
        {
            if (nums[pos] < nums[i]) pos = i;
        }

        TreeNode *res = new TreeNode(nums[pos]);

        res->left = constructMaximumBinaryTreeRange(nums, left, pos - 1);
        res->right = constructMaximumBinaryTreeRange(nums, 1 + pos, right);


        return res;
    }

    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) { return constructMaximumBinaryTreeRange(nums, 0, nums.size() - 1); }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
