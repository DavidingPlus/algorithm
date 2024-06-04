/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start

#include <iostream>
#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        int n = coins.size();

        // 经典完全背包问题
        // dp[i][j] 表示使用前 i 中硬币能凑成的 j 面值的硬币组合数
        // 还能这样直接初始化二维 std::vector ？？？？
        std::vector<std::vector<int>> dp(n, std::vector<int>(1 + amount));

        // 初始化第一行
        for (int j = 0; j < 1 + amount; ++j)
        {
            if (0 == j % coins[0])
            {
                dp[0][j] = 1;
            }
        }

        // 公式自己画一个图就推导出来了
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < 1 + amount; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i])
                {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }

        return dp[n - 1][amount];
    }
};

// @lc code=end
