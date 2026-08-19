#
# @lc app=leetcode.cn id=213 lang=python3
#
# [213] 打家劫舍 II
#

# @lc code=start
class Solution:
    # 上一个题目的代码逻辑，不考虑房屋首位相邻的逻辑
    def stealMoney(self, nums: list) -> int:
        # 还是下标从 1 开始，这次就用两个数存储了
        dp0, dp1 = 0, nums[0]
        for i in range(2, 1+len(nums)):
            tmp = max(dp1, nums[i-1]+dp0)
            dp0 = dp1
            dp1 = tmp
        return dp1

    def rob(self, nums: list) -> int:
        # 这个题目和上一个题目唯一的区别就是首尾相邻，导致第一个房子和最后一个房子不能同时偷取，最多只能偷取一个
        # 结合上一个题目的逻辑，dp[i] 表示在[第一个房子下标,i]的范围里面偷取的最大金额，因此结合到本题，如果第一个房子偷取，那么最后一个房子就可以偷取，因此范围是[第二个房子下标, 最后一个房子下标]；同理，另一个范围是[第一个房子下标, 最后一个房子下标 - 1]；关于两个房子都不偷取，由于 dp[i] 是在偷取 i 和不偷取 i 的情况取得最大值，因此都不偷取的情况是做了比较的，这里不用担心

        # 由于需要去掉一个元素，因此做一个特判
        if 1 == len(nums):
            return nums[0]

        return max(self.stealMoney(nums[0:len(nums)-1]),
                   self.stealMoney(nums[1:len(nums)]))
# @lc code=end
