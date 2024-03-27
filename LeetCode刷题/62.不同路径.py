#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#

# @lc code=start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 某个点的路径个数和左边的和上面的相关，找到状态转移方程
        # 处理第一行
        dp = [1] * n
        for i in range(1, m):
            tmp = [1] * n  # 每行的第 1 列一定只有 1 条路径，直着下来
            for j in range(1, n):
                tmp[j] = tmp[j-1]+dp[j]
            dp = tmp
        return dp[n-1]
# @lc code=end
