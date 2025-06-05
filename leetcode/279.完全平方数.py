#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start
from math import sqrt

topNum = 10 ** 4+10


class Solution:
    # n 的最大值是 10 ** 4 ，保险起见，加上 10
    memo = [-10086 for _ in range(1, topNum)]

    def numSquares(self, n: int) -> int:
        # 每个数都可以拆分为一个完全平方数加上另一堆组合，而这一堆组合就可以调用递归了，再取最小值即可，这就是动态规划的思想
        # 由于 n - i ** 2 不可能比 0 小，所以边界条件不用考虑 n < 0
        if 0 == n:
            return 0

        if -10086 == self.memo[n]:
            res = topNum
            top = int(sqrt(n))

            for i in range(1, 1+top):
                res = min(res, 1 + self.numSquares(n - i ** 2))
            self.memo[n] = res
        return self.memo[n]

# @lc code=end
