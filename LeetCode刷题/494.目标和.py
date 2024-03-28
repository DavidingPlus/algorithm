#
# @lc app=leetcode.cn id=494 lang=python3
#
# [494] 目标和
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        # 有正有负，也就是说将这些数分成两堆，让他们的和相差为 target；换一个思维就是说有多少种选择方案选择 nums 中的元素，让他们的和为 (sum(nums) + target) // 2（或者是 (sum(nums) - target) // 2；当然从这里可以看出二者的值相加必须为偶数，否则无法构成
        # 从题目上直接看， target 的正负与答案无关，取绝对值即可
        totalSum = sum(nums)

        if (totalSum + abs(target)) & 1:
            return 0

        actualTarget = (totalSum + abs(target)) // 2
        # dp[i][j] 代表的含义是使用 [0, i] 的数构成和 j 的方案数
        dp = [0]*(1+actualTarget)
        # 凑出 0 的意思是我不选，两份里面有一份是空，这个在原题上是复合逻辑的，这里需要注意
        dp[0] = 1
        # TODO 算法是对了，但是这里为什么不能初始化？
        # for j in range(1, 1+actualTarget):
        #     dp[j] = 1 if j == nums[0] else 0

        for i in range(0, len(nums)):
            tmp = [0]*(1+actualTarget)
            tmp[0] = 1
            for j in range(0, 1+actualTarget):
                if j < nums[i]:
                    tmp[j] = dp[j]
                else:
                    # 如果无法构成，表格中填入的是 0，注意这一点就很简单了
                    tmp[j] = dp[j] + dp[j-nums[i]]
            dp = tmp
            print(dp)
        return dp[actualTarget]

# @lc code=end
