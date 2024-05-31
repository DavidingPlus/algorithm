# 区间修改、区间查询（线段树 + 延迟标记 tag 优化）
# https://www.lanqiao.cn/problems/1133/learning/

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

N = int(input())
nums = list(map(int, input().split()))

f = [0 for _ in range(1+4*N)]

# TODO
