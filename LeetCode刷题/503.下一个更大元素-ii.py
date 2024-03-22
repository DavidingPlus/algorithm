#
# @lc app=leetcode.cn id=503 lang=python3
#
# [503] 下一个更大元素 II
#

# @lc code=start
class Solution:
    def nextGreaterElements(self, nums: list[int]) -> list[int]:
        # 让原数组拼到后面成为两倍即可解决问题
        # [1, 2, 1, 1, 2, 1]
        nextNums = [-1]*len(nums)
        s = []
        i = 2*len(nums)-1
        while i >= 0:
            while 0 != len(s) and nums[i % len(nums)] >= s[len(s)-1]:
                s.pop(len(s)-1)
            if 0 == len(s):
                nextNums[i % len(nums)] = -1
            else:
                nextNums[i % len(nums)] = s[len(s)-1]
            s.insert(len(s), nums[i % len(nums)])
            i -= 1
        return nextNums

# @lc code=end
