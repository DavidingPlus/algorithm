#
# @lc app=leetcode.cn id=494 lang=python3
#
# [494] 目标和
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        # 有正有负，也就是说将这些数分成两堆，让他们的和相差为 target；换一个思维就是说有多少种选择方案选择 nums 中的元素，让他们的和为 (sum(nums) + target) // 2；当然从这里可以看出二者的值相加必须为偶数，否则无法构成
        totalSum = sum(nums)
        if (totalSum + target) & 1:
            return 0
        actualTarget = (totalSum+target)//2
        # dp[i][j] 代表的含义是使用 [0, i] 的数构成和 j 的方案数
        # TODO 这个代码还有 bug
        dp = [0] * (1+actualTarget)
        for j in range(0, 1+actualTarget):
            dp[j] = 1 if j == nums[0] else 0
        for i in range(1, len(nums)):
            tmp = [0]*(1+actualTarget)
            for j in range(0, 1+actualTarget):
                if j < nums[i]:
                    tmp[j] = dp[j]
                else:
                    # 如果无法构成，表格中填入的是 0，注意这一点就很简单了
                    tmp[j] = dp[j] + dp[j-nums[i]]
            dp = tmp
        return dp[actualTarget]

# @lc code=end
