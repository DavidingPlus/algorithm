/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int change(int amount, std::vector<int> &coins)
    {
        int n = coins.size();

        // 经典完全背包问题，dp[i][j] 表示使用前 i 个凑成面额 j 的组合数（i 从 0 开始）
        // 二维 vector 可以这样初始化，第一个参数是第一维的大小，第二个参数就是初始化第二维的 vector
        std::vector<std::vector<int>> dp(n, std::vector<int>(1 + amount));

        // 初始化第一行
        for (int j = 0; j <= amount; ++j) dp[0][j] = (0 == j % coins[0]) ? 1 : 0;

        // 继续迭代
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= amount; ++j)
            {
                // 可以不使用第 i 个
                dp[i][j] = dp[i - 1][j];

                // 如果要使用需要符合面值条件
                if (j >= coins[i]) dp[i][j] += dp[i][j - coins[i]];
            }
        }

        return dp[n - 1][amount];
    }
};

// @lc code=end
