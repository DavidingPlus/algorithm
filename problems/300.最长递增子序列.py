#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长递增子序列
#

# @lc code=start
class Solution:
    def lengthOfLIS(self, nums: list) -> int:
        dp = [1]
        res = 1  # 最差的情况下是 1 ，就是自身
        for i in range(1, len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], 1+dp[j])
            res = max(res, dp[i])
        return res

# @lc code=end
