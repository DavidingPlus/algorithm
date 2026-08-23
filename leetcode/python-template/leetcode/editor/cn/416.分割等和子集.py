#
# @lc app=leetcode.cn id=416 lang=python3
#
# [416] 分割等和子集
#

# @lc code=start
class Solution:
    # # 这个想法挺好，但是空间复杂度是 O(n^2) ，内存肯定受不了
    # def canPartition(self, nums) -> bool:
    #     # 言下之意就是说能否找到一个子集，其和为数组和的一半
    #     totalSum = sum(nums)
    #     if totalSum & 1:
    #         return False
    #     # 下面的线性规划没有把初始情况做判断，这里做一个特判：
    #     if totalSum // 2 == nums[0]:
    #         return True

    #     # 用 dp 表示所有可能的子集的和的集合
    #     # 对于新进来的元素，新构成的组合就是前面的所有元素的组合加上新元素，或者新元素本身，这样就能够得出所有的组合
    #     dp = [nums[0]]
    #     for i in range(1, len(nums)):
    #         tmp = []
    #         for e in dp:
    #             if totalSum // 2 == e + nums[i]:
    #                 return True
    #             tmp.append(e + nums[i])
    #         # append 只能放元素，不能放列表，+= 都可以
    #         dp += tmp
    #     return False

    # 借鉴背包问题的思路
    def canPartition(self, nums) -> bool:
        totalSum = sum(nums)
        if totalSum & 1:
            return False
        target = totalSum // 2

        # 由于本题只是判断是否可以分为，因此可以使用 dp[i][j] 表示 [0, i] 的数组能否恰好组成和为 j，这样就找到了状态转移方程
        # 对于 dp[i][j]，分为两种情况，装入 i ，不装入 i ，不装入 i 的结果就和 dp[i-1][j] 一样，装入的话，剩下的空间是 j - nums[i] ，取决于这个能不能装下，也就是 dp[i-1][j - nums[i]]
        # 用一维数组优化空间复杂度
        dp = [False] * (1 + target)
        for j in range(0, 1+target):
            dp[j] = (j == nums[0])

        for i in range(1, len(nums)):
            tmp = [False] * (1 + target)
            for j in range(1, 1+target):
                if j - nums[i] < 0:
                    tmp[j] = dp[j]
                else:
                    tmp[j] = dp[j] or dp[j - nums[i]]
            dp = tmp
        return dp[target]


# @lc code=end
