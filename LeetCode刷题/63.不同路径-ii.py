#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        # 这题和上一题的区别在于加上了障碍物，和简单，障碍物的位置路径条数为 0 ，因为没有人能到达
        m, n = len(obstacleGrid), len(obstacleGrid[0])

        # 处理第一行，找到第一个障碍物即可
        dp = [0] * n
        for j in range(0, n):
            if 1 != obstacleGrid[0][j]:
                dp[j] = 1  # 初始化赋值的是 0 ，这里更改为 1 ，因此下面遇到障碍物就 break 即可
            else:
                break

        for i in range(1, m):
            tmp = [0] * n
            for j in range(0, n):
                # 本位置是障碍物，设置为 0
                if 1 == obstacleGrid[i][j]:
                    tmp[j] = 0
                else:
                    # 由于第一行也有可能到不了，因此需要特判
                    tmp[j] = dp[j] if 0 == j else tmp[j-1]+dp[j]
            dp = tmp
        return dp[n-1]
# @lc code=end
