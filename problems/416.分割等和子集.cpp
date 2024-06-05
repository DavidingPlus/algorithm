/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start

#include <vector>
#include <iostream>

class Solution
{

public:
    bool canPartition(std::vector<int> &nums)
    {
        int n = nums.size();

        // 经典的 01 背包问题
        int sum = 0;
        for (auto &v : nums)
        {
            sum += v;
        }

        if (sum & 1)
        {
            return false;
        }

        // 使用滚动数组优化空间复杂度
        // std::vector<std::vector<int>> dp(1 + n, std::vector<int>(1 + sum / 2));
        // dp[0][0] = true;
        std::vector<int> dp(1 + sum / 2);
        dp[0] = true;

        for (int i = 1; i < 1 + n; ++i)
        {
            std::vector<int> tmp(1 + sum / 2);
            for (int j = 0; j < 1 + sum / 2; ++j)
            {
                tmp[j] = dp[j];
                if (j >= nums[i - 1])
                {
                    tmp[j] |= dp[j - nums[i - 1]];
                }
            }
            dp = tmp;
        }

        return dp[sum / 2];
    }
};

// @lc code=end
