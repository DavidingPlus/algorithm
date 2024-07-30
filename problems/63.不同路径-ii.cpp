/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start

#include <vector>


class Solution
{

public:

    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        std::vector<int> dp(n);
        dp[0] = 1; // 将第一行纳入统一迭代推导出的合理的初始条件（相当于添加 -1 行）

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 置障碍物的步数为 0
                if (1 == obstacleGrid[i][j])
                {
                    dp[j] = 0;
                }
                // 其余同理
                else
                {
                    if (0 != j) dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end
