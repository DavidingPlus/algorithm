#
# @lc app=leetcode.cn id=518 lang=python3
#
# [518] 零钱兑换 II
#

# @lc code=start

class Solution:
    def change(self, amount: int, coins: list) -> int:
        # 这个题目用一维的分析好像不行，例如 1 2 组成 3；这样出来 1 + dp[2] 和 2 + dp[1] 是一种方法，就重复了
        # 但是这个题目和 01 背包问题非常相似， dp[i][j] 表示使用前 i 个凑成面值为 j 的组合数
        # 做空间复杂度的优化
        dp = [[0 for _ in range(1+amount)]for _ in range(2)]
        # 处理第一行
        for j in range(1+amount):
            if 0 == j % coins[0]:  # 经过题目测试样例测试， amount 为 0 的时候返回 1
                dp[0][j] = 1

        for i in range(1, len(coins)):
            for j in range(1+amount):
                if j-coins[i] < 0:
                    dp[i & 1][j] = dp[1 - i & 1][j]
                else:
                    # 注意，这个货币可能可以使用很多次，所以需要循环
                    dp[i & 1][j] = dp[1 - i & 1][j]
                    k = j
                    while True:
                        k -= coins[i]
                        if k < 0:
                            break
                        dp[i & 1][j] += dp[1 - i & 1][k]
        return dp[(len(coins)-1) & 1][amount]


# @lc code=end
