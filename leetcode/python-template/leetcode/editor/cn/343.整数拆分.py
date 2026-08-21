#
# @lc app=leetcode.cn id=343 lang=python3
#
# [343] 整数拆分
#

# @lc code=start
class Solution:
    def integerBreak(self, n: int) -> int:
        # n >= 2
        # 用 dp[i] 记录 i 对应的最大乘积
        dp = [1, 1]  # 初始条件 dp[1] == 1（根据题目得出的）
        for i in range(2, n+1):
            tmp = -1
            for j in range(1, i):
                # 假设我知道 1 到 n 的规律要推 n + 1
                # n + 1 可以拆分为 (1, n),(2, n - 1)等，如何保证拆分的情况完全呢？就让第二项可以拆分，也就是取 dp[i-j]，注意 dp[] 没有包含这个数字本身不拆分的情况，因此也可以不拆分，也就是取 i-j ，这样就周全了
                tmp = max(tmp, j * (max(i-j, dp[i-j])))
            dp.append(tmp)
        return dp[n]

# @lc code=end
