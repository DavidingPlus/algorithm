# 单点修改，区间查询
# https://www.lanqiao.cn/problems/2340/learning/

from math import sqrt

# 通过分块的思想进行优化
N = int(input())
nums = list(map(int, input().split()))

# 计算出分块出来的区间的长度，最佳的值是根号 n ，这里为了防止为 0 ，加 1
each = int(sqrt(N))+1
sums = [0 for _ in range(N//each if 0 == N % each else 1+N//each)]
for i in range(N):
    sums[i//each] += nums[i]

m = int(input())
for _ in range(m):
    l = list(map(int, input().split()))
    if 1 == l[0]:
        sums[l[1]//each] += l[2]
    else:
        # TODO
