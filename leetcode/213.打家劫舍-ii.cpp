/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 此函数计算不考虑首尾相连的偷盗 [left, right] 的情况
    int robNoCircle(const std::vector<int> &nums, int left, int right)
    {
        // 为了防止下面越界，加上边界判断
        if (left > right) return 0;

        int n = right - left + 1;

        std::vector<int> dp(1 + n);
        dp[0] = 0, dp[1] = nums[left];

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = std::max(nums[i - 1 + left] + dp[i - 2], dp[i - 1]);
        }

        return dp[n];
    }

    int rob(std::vector<int> &nums)
    {
        // 这题与上一题的唯一区别就是首尾不能同时偷，因此关于首尾偷与不偷的状态，有三种情况，取最大值即可
        int res = -1, n = nums.size();

        // 第一，首部偷，尾部不偷
        res = std::max(res, nums[0] + robNoCircle(nums, 2, n - 2));
        // 第二，首部不偷，尾部偷
        res = std::max(res, nums[n - 1] + robNoCircle(nums, 1, n - 3));
        // 第三，首部不偷，尾部也不偷
        res = std::max(res, robNoCircle(nums, 1, n - 2));

        return res;
    }
};

// @lc code=end
