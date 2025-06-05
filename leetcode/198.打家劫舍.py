#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#

# @lc code=start
class Solution:
    def rob(self, nums: list) -> int:
        # dp[i] 代表只偷取 [0, i] 的房子能拿到的最多的钱
        # 对于 i ，有两种方式，一种是偷，另一种是不偷；偷的话 dp[i-1] 就偷不了，不偷的话 dp[i-1] 就有机会偷，因此状态转移方程就出来了
        dp = [-1] * (1+len(nums))
        # 房子的下标从 1 开始，因为有 dp[i-2]，事实上，动态规划的题目一般都是从 1 开始
        dp[0], dp[1] = 0, nums[0]
        ans = dp[1]
        for i in range(2, 1+len(nums)):
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2])
            ans = max(ans, dp[i])
        return ans
# @lc code=end
