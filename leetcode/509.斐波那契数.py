#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start

# 方法1： 备忘录递归
# memo = [-1] * (30 + 10)


# class Solution:
#     def fib(self, n: int) -> int:
#         if 0 == n or 1 == n:
#             return n
#         if -1 == memo[n]:
#             memo[n] = self.fib(n - 1) + self.fib(n - 2)
#         return memo[n]


# 方法2： 迭代
dp = [0] * (30 + 10)


class Solution:
    def fib(self, n: int) -> int:
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]

# @lc code=end
