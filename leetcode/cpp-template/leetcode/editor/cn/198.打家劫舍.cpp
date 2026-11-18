/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    // 空间复杂度优化版本。
    int rob(std::vector<int> &nums)
    {
        int n = nums.size();

        int dp_i_minus_2 = 0, dp_i_minus_1 = nums[0];

        for (int i = 2; i <= n; ++i)
        {
            int dp_i = std::max(nums[i - 1] + dp_i_minus_2, dp_i_minus_1);
            dp_i_minus_2 = dp_i_minus_1;
            dp_i_minus_1 = dp_i;
        }


        return dp_i_minus_1;
    }


    // int rob(std::vector<int> &nums)
    // {
    //     // 线性 dp，代表偷前 i 个房屋的能获得的最大金额
    //     int n = nums.size();

    //     // 为了优化空间复杂度，可以使用两个数 a 和 b 存储 dp[i - 2] 和 dp[i - 1] 即可。
    //     std::vector<int> dp(1 + n);
    //     dp[0] = 0, dp[1] = nums[0];

    //     // 当前房屋的状态分为两种，偷当前房间和不偷当前房间，取二者的最大值即可。
    //     for (int i = 2; i <= n; ++i) dp[i] = std::max(nums[i - 1] + dp[i - 2], dp[i - 1]);


    //     return dp[n];
    // }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
