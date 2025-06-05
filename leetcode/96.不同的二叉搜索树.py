#
# @lc app=leetcode.cn id=96 lang=python3
#
# [96] 不同的二叉搜索树
#

# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        # 每个节点都有可能做根节点，而根节点的值确定了之后，左右子树的节点就确定了
        dp = [1, 1]
        for i in range(2, n+1):
            count = 0
            for j in range(1, i+1):
                leftCnt = j-1 if 1 != j else 0  # 这里返回 0 纯粹是看 dp[0] == 0
                rightCnt = i-j if i != j else 0
                count += dp[leftCnt]*dp[rightCnt]
            dp.append(count)
        return dp[n]
# @lc code=end
