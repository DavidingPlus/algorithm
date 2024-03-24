#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    # 作备忘录，记录凑成面额为 i 的最小硬币个数
    memo = [-666] * (pow(10, 4)+10)

    def coinChange(self, coins: list[int], amount: int) -> int:
        if 0 == amount:
            return 0
        if amount < 0:
            return -1

        if -666 != self.memo[amount]:
            return self.memo[amount]

        res = pow(10, 4)+10
        for i in range(len(coins)):
            count = self.coinChange(coins, amount - coins[i])
            if -1 == count:
                continue
            res = min(res, 1+count)

        self.memo[amount] = -1 if pow(10, 4)+10 == res else res

        return self.memo[amount]

# @lc code=end


s = Solution()
print(s.coinChange([2], 3))  # -1，但是 leetCode 返回 2 ，我不知道为什么。。。
