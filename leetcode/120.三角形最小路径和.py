#
# @lc app=leetcode.cn id=120 lang=python3
#
# [120] 三角形最小路径和
#

# @lc code=start
class Solution:
    def minimumTotal(self, triangle: list) -> int:
        n = len(triangle)
        if 0 == n:
            return 0

        dp = [triangle[0][0]]
        for i in range(1, n):
            tmp = [0 for _ in range(1+i)]
            for j in range(1+i):
                if 0 == j:
                    tmp[j] = triangle[i][j]+dp[j]
                elif j == i:
                    tmp[j] = triangle[i][j]+dp[j-1]
                else:
                    tmp[j] = triangle[i][j]+min(dp[j], dp[j-1])
            dp = tmp
        return min(dp)
# @lc code=end
