#
# @lc app=leetcode.cn id=1143 lang=python3
#
# [1143] 最长公共子序列
#

# @lc code=start
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        if 0 == m or 0 == n:
            return 0

        # dp[i][j] 代表 text1 的 [0, i] 和 text2 的 [0, j] 的最长公共子序列，本题运作方式很像编辑距离那题，具体的逻辑就不写了，只需要知道最长公共子序列的变动方式即可
        dp = [0 for _ in range(n)]
        # 初始化第一行
        for j in range(n):
            dp[j] = 1 if text1[0] in text2[0:1+j] else 0

        # 开始循环
        for i in range(1, m):
            tmp = [0 for _ in range(n)]
            for j in range(n):
                if 0 == j:
                    tmp[0] = 1 if text2[0] in text1[0:1+i] else 0
                else:
                    # 还是分最后一个相同和不同的情况
                    if text1[i] == text2[j]:
                        tmp[j] = 1+dp[j-1]
                    else:
                        # 不相等的情况下，分别可以通过 dp[i-1][j]，dp[i][j-1] 和 dp[i-1][j-1] 三种方式来获得结果，具体的逻辑如果分析不出来可以参考编辑距离那个题
                        tmp[j] = max(tmp[j-1], dp[j], dp[j-1])
            dp = tmp
        return dp[n-1]
# @lc code=end
