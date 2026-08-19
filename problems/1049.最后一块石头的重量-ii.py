#
# @lc app=leetcode.cn id=1049 lang=python3
#
# [1049] 最后一块石头的重量 II
#

# @lc code=start
class Solution:
    def lastStoneWeightII(self, stones: list[int]) -> int:
        # 跟着示例走画一个图，发现题目石头碰撞的过程，相当于是把一块石头分成两堆，然后相互碰撞，知道剩下小于等于一块石头，那么把碰撞消去的重量加上，这个问题就转化为了如何将一块石头分为两堆，使其重量差最接近，再转换一下，一个合适的子集，使其具有的重量最大，并且不大于总重量的一半，这就是一个 01 背包问题了
        # 这里注意一点，总重量是偶数，targhtWeight 是正好一半这没毛病；总重量是奇数的情况下，例如 25 // 2 = 12 ，这时凑出 12 和 13 或者 13 和 12 是一样的，因此可取下整，不超过 12
        totalWeight = sum(stones)
        targhtWeight = totalWeight // 2

        dp = [0] * (1 + targhtWeight)
        for j in range(0, 1 + targhtWeight):
            dp[j] = stones[0] if j >= stones[0] else 0

        for i in range(1, len(stones)):
            tmp = [0] * (1 + targhtWeight)
            for j in range(0, 1 + targhtWeight):
                if j < stones[i]:
                    tmp[j] = dp[j]
                else:
                    tmp[j] = max(dp[j], stones[i] + dp[j-stones[i]])
            dp = tmp
        return abs(2 * dp[targhtWeight] - totalWeight)

# @lc code=end
