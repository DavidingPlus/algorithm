#
# @lc app=leetcode.cn id=221 lang=python3
#
# [221] 最大正方形
#

# @lc code=start
class Solution:
    def maximalSquare(self, matrix: list) -> int:
        m, n = len(matrix), len(matrix[0])

        # dp[i][j] 代表以 [i, j] 为右下角的只包含 1 的最大的正方形的边长，注意答案求的是面积
        # 用一维数组优化空间复杂度
        dp = [0 for _ in range(n)]
        # 第一行的要么是 0，要么是 1
        ans = 0
        for j in range(n):
            dp[j] = 1 if "1" == matrix[0][j] else 0
            ans = max(ans, dp[j])
        # 开始循环
        for i in range(1, m):
            tmp = [0 for _ in range(n)]
            for j in range(0, n):
                # 处在边上的点和第一行处理方式一样
                if 0 == j:
                    tmp[0] = 1 if "1" == matrix[i][0] else 0
                else:
                    if "0" == matrix[i][j]:
                        tmp[j] = 0
                    else:
                        # 如果这一个点是 3 ，那么它左边、上边、左上边都应该是 2 ，反推猜想是这三者的最小值 加 1；经过验证发现符合条件
                        tmp[j] = 1+min(dp[j], tmp[j-1], dp[j-1])
                ans = max(ans, tmp[j])
            dp = tmp
        return ans * ans

# @lc code=end
