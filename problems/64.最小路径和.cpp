/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        // 用 dp[i][j] 代表到达该位置的最小路径和
        // 可以只开 2 行，但是不能使用静态数组，因为行数确定，但列数不确定，不能开静态数组，编译器无法确定，因此可能会出现错误
        std::array<std::vector<int>, 2> dp;
        for (auto &line : dp)
        {
            line.resize(n);
        }

        // 初始化第一行
        dp[0][0] = grid[0][0];
        for (int j = 1; j < n; ++j)
        {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        // 开始迭代
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (0 == j)
                {
                    dp[i & 1][j] = grid[i][j] + dp[1 - i & 1][j];
                }
                else
                {
                    dp[i & 1][j] = grid[i][j] + std::min(dp[1 - i & 1][j], dp[i & 1][j - 1]);
                }
            }
        }
        return dp[(m - 1) & 1][n - 1];
    }
};
// @lc code=end
