#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        # 类似于斐波那契，这里用两个数存储优化空间复杂度
        if 0 == n or 1 == n:
            return 1
        a = 1
        b = 1
        for i in range(2, n+1):
            tmp = a + b
            a = b
            b = tmp
        return b
# @lc code=end
