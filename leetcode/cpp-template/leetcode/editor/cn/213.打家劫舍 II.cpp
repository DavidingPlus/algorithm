/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30404
 *
 * [213] 打家劫舍 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    // 在 198 题的基础上继续考虑。
    int rob(std::vector<int> &nums)
    {
        // 题目要求首尾不能同时抢，那只有三种情况，一是首抢尾不抢，二是尾抢首不抢，三是首部尾部都不抢。
        // 对于这三种情况，各自能任意抢夺的区间就会发生改变，比如首抢尾不抢，可以开始抢夺的起点就是第三间房子，终点就是倒数第二间房子，其他同理，因此维护一个工具函数，用于计算任意区间的 dp 值即可。
        int res = 0, n = nums.size();

        res = std::max(res, nums[0] + dp(nums, 2, n - 2));
        res = std::max(res, nums[n - 1] + dp(nums, 1, n - 3));
        res = std::max(res, dp(nums, 1, n - 2));


        return res;
    }

    // 计算 [left, right] 中能够抢到的最大值（即 198 题）。
    int dp(const std::vector<int> &nums, int left, int right)
    {
        if (left > right) return 0;

        int dp_i_minus_2 = 0, dp_i_minus_1 = nums[left];

        for (int i = 1 + left; i <= right; ++i)
        {
            int dp_i = std::max(nums[i] + dp_i_minus_2, dp_i_minus_1);
            dp_i_minus_2 = dp_i_minus_1;
            dp_i_minus_1 = dp_i;
        }


        return dp_i_minus_1;
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
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
