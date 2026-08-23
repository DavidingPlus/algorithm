#
# @lc app=leetcode.cn id=1046 lang=python3
#
# [1046] 最后一块石头的重量
#

# @lc code=start
class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        # 这题暴力就过了？？？
        while len(stones) > 1:
            stones.sort(reverse=True)
            if stones[0] != stones[1]:
                stones.append(stones[0]-stones[1])
            for i in range(2):
                stones.pop(0)  # 弹掉第一个之后，第二个下标就变成 0 了，所以还是 pop(0)
        return 0 if 0 == len(stones) else stones[0]
# @lc code=end
