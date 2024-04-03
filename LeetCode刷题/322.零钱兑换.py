#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
import sys


class Solution:

    # 用动态规划的迭代的思维来做
    def coinChange(self, coins: list, amount: int) -> int:
        dp = [0]  # dp[i] 表示凑出 i 面值需要的最小硬币个数
        for i in range(1, 1+amount):
            count = sys.maxsize
            for c in coins:
                if i-c >= 0 and -1 != dp[i-c]:
                    count = min(count, 1+dp[i-c])
            if sys.maxsize == count:
                dp.append(-1)
            else:
                dp.append(count)
        return dp[amount]


# @lc code=end
