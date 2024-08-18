/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int rob(std::vector<int> &nums)
    {
        // 线性 dp，代表偷前 i 个房屋的能获得的最大金额
        int n = nums.size();

        // 为了优化空间复杂度，可以使用两个数 a 和 b 存储 dp[i-2] 和 dp[i-1] 即可，这里略
        std::vector<int> dp(1 + n);
        dp[0] = 0, dp[1] = nums[0];

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = std::max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }

        return dp[n];
    }
};

// @lc code=end
