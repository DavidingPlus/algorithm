# coding:utf-8
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        # 由于下面 word1[0] 和 word2[0] 需要下标索引，因此这里对二者有一个为 0 做特判
        if 0 == m or 0 == n:
            return abs(m-n)

        # 记住一个规律，绝大部分关于字符串的动态规划题目都可以使用二维数组解决，并且绝大多数使用的是二维数组（所以尽量往背包问题上去靠）
        # 定义 dp[i][j] 是 word1 的 [0, i] 转化到 word2 的 [0, j] 的最小操作数，找出状态转移方程
        # 优化空间复杂度，用一个一维数组存储
        dp = [0 for _ in range(n)]
        # 初始化第一行，一个字符变成一个字符串，最简洁的办法就是增加然后替换，是否替换取决于这个字符是否存在于字符串中
        for j in range(n):
            dp[j] = 1+j if word1[0] not in word2[0:1+j] else j

        # 状态转移方程
        # 考虑 dp[i][j]，对于 word1[i] 和 word2[j] 的关系，无非就是相等和不相等
        # 如果 word1[i] 和 word2[j] 相等，那么最后一位不用转换，就等于 dp[i-1][j-1]
        # 如果不相等，就有几种情况了可以让其相等了：第一，word1 的 [0, i-1] 转化为 word2 的 [0, j]，然后删去 word1 的最后一位即可， 1 + dp[i-1][j]；第二， word1 的 [0, i] 转化为 word2 的 [0, j-1]，然后加上最后一位即可， 1 + dp[i][j-1]；第三，word1 的 [0, i-1] 转化为 word2 的 [0, j-1],最后一位替换即可， 1 + dp[i-1][j-1]。至于为什么会考虑这三招那个情况呢？因为对于每一位而言，就有三种操作，加，删，换
        for i in range(1, m):
            tmp = [0 for _ in range(n)]
            for j in range(n):
                # 当 j == 0 的时候，可以直接人为计算出来，逻辑和上面初始化第一行一致
                if 0 == j:
                    tmp[0] = 1+i if word2[0] not in word1[0:1+i] else i
                else:
                    if word1[i] == word2[j]:
                        tmp[j] = dp[j-1]
                    else:
                        tmp[j] = min(1+dp[j], 1+tmp[j-1], 1+dp[j-1])
            dp = tmp
            print(dp)
        return dp[n-1]
        # @lc code=end
