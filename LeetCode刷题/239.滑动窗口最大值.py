#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        res = []
        q = []
        # note： 其实这个严格意义来讲应该交单调双端队列
        # 然后维持单调队列性质
        # 这个 i 代表滑动窗口的末尾下标，从 0 开始，包含了初始状态
        for i in range(0, len(nums)):
            # 先看队头是否出队
            if 0 != len(q) and i - k + 1 > q[0]:
                q.pop(0)
            while 0 != len(q) and nums[i] >= nums[q[len(q)-1]]:
                q.pop(len(q)-1)
            q.insert(len(q), i)
            if i - k + 1 >= 0:
                res.append(nums[q[0]])
        return res

# @lc code=end
