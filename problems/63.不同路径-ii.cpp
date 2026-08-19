/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        std::vector<int> dp(n);
        dp[0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (1 == obstacleGrid[i][j])
                {
                    dp[j] = 0;
                }
                else
                {
                    if (j) dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

// @lc code=end
