#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: list) -> int:
        if 0 == len(nums):
            return 0

        # dp[i] 表示以 i 结尾使用 [0, i] 的最大连续子数组和
        dp = nums[0]
        ans = dp
        for i in range(1, len(nums)):
            # 对于 dp[i] ，既然 dp[i] 的定义是以 i 结尾的最大连续子数组和，那么 i 首先肯定需要，那么前面的那一串，可以要也可以不要，并且如果要了，由于是连续的，只能取最大的 dp[i-1]，其他的段都小于这个值，因此决定权就在 dp[i-1] 的正负了
            dp = nums[i] + dp if dp >= 0 else nums[i]
            ans = max(ans, dp)
        return ans
# @lc code=end
