from bisect import *


# 求两个字符串的最长子串
def longestSubStr(s1: str, s2: str):
    # 从最大的开始匹配，找到了直接返回
    ans = len(s1)
    while ans > 0:
        for i in range(0, 1+len(s1)-ans):
            if s1[i:i+ans] in s2:
                return ans
        ans -= 1
    return ans


# 求两个环形字符串的最长子串
def longestSubStrCircle(s1: str, s2: str):
    res = 0
    for _ in range(0, len(s2)):
        res = max(res, longestSubStr(s1, s2))
        c = s2[0]
        s2 = s2[1::] + c
    return res


n, m = map(int, input().split())
strs = []
for _ in range(n):
    strs.append(input())


l = []
for i in range(n):
    for j in range(1+i, n):
        insort(l, longestSubStrCircle(strs[i], strs[j]))
print(sum(l[len(l)-n+1:len(l)]))
