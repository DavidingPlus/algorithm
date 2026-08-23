#
# @lc app=leetcode.cn id=516 lang=python3
#
# [516] 最长回文子序列
#

# @lc code=start
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        # 这个题使用一维会出现问题，考虑测试数据 aabaa，前四个没有头问题，但是最后一个答案是 5，包含了自身，而去除末尾的这一个并不是回文子序列，因此考虑二位

        # TODO

    def check(self, s: str) -> bool:
        return s == s[::-1]
# @lc code=end
