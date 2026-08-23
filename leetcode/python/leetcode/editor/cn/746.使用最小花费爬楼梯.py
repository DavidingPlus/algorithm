#
# @lc app=leetcode.cn id=746 lang=python3
#
# [746] 使用最小花费爬楼梯
#

# @lc code=start
class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        # 和上一题没有区别，只不过需要更新最低花费
        if len(cost) <= 2:
            return min(cost)
        a, b = 0, 0
        # 注意我们需要计算 cost 的最后一个的下一个的费用，注意范围
        for i in range(2, 1 + len(cost)):
            tmp = min(a + cost[i-2], b + cost[i-1])
            a = b
            b = tmp
        return b
# @lc code=end
