#
# @lc app=leetcode.cn id=139 lang=python3
#
# [139] 单词拆分
#

# @lc code=start
class Solution:
    # 用 memo 记录一下，减少时间复杂度
    memo = set()

    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        # 注意，这个题目第一眼可能想到可以笨蛋的使用字符串的 replace 方法，遇到一个替换掉一个，能够过大部分的点，但有一些点是过不了的
        # 例如 s = "cars", wordDict = ["car","ca","rs"]

        # 对于能够拼凑出来的解， wordDict 中的每个元素都有可能作为前缀，例如上面的 "car" 和 "ca" ，但是不一定每个都是正确的，这就上面那个思路的缺陷
        # 递归出口
        # TODO 该算法在力扣上跑的结果不对，但是本地是对的，数据 "a", ["b"]
        if s in self.memo:
            return True

        if s in wordDict:
            self.memo.add(s)
            return True

        for e in wordDict:
            if e == s[0:len(e)] and self.wordBreak(s[len(e)::], wordDict):
                self.memo.add(s[len(e)::])
                return True
        return False


# @lc code=end
