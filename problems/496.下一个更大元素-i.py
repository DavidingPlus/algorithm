#
# @lc app=leetcode.cn id=496 lang=python3
#
# [496] 下一个更大元素 I
#

# @lc code=start
class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        # 先计算 num2 的每个数的下一个更大元素的值
        nextNums2 = [-1] * len(nums2)
        s = []  # 栈
        i = len(nums2) - 1
        while i >= 0:
            while 0 != len(s) and nums2[i] >= s[len(s)-1]:
                s.pop(len(s)-1)
            if 0 == len(s):
                nextNums2[i] = -1
            else:
                nextNums2[i] = s[len(s)-1]
            s.insert(len(s), nums2[i])
            i -= 1
        # 遍历 nums1 拿到对应的值即可
        ans = []
        for e in nums1:
            ans.append(nextNums2[nums2.index(e)])
        return ans


# @lc code=end
