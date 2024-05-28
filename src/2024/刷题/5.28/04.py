# 区间选树 k
# https://www.lanqiao.cn/courses/38752/learning/

# TODO 超时 7/10

from math import log2

# 维护两个 ST 表即可
n, m = map(int, input().split())
nums = list(map(int, input().split()))
querys = [[0 for _ in range(2)] for _ in range(m)]
for i in range(m):
    querys[i] = list(map(int, input().split()))

MAX = 1+int(log2(n))
fMin = [[0 for _ in range(MAX)] for _ in range(n)]
fMax = [[0 for _ in range(MAX)] for _ in range(n)]

# 预处理 ST 表
for i in range(n):
    fMin[i][0] = nums[i]
    fMax[i][0] = nums[i]

for j in range(1, MAX):
    for i in range(n):
        if i+(1 << (j-1)) >= n:
            fMin[i][j] = fMin[i][j-1]
            fMax[i][j] = fMax[i][j-1]
        else:
            fMin[i][j] = min(fMin[i][j-1], fMin[i+(1 << (j-1))][j-1])
            fMax[i][j] = max(fMax[i][j-1], fMax[i+(1 << (j-1))][j-1])

ansMin = 0
ansMax = 0
for i in range(m):
    l, r = querys[i]
    l -= 1
    r -= 1

    j = int(log2(r-l+1))
    ansMin += min(fMin[l][j], fMin[r+1-(1 << j)][j])
    ansMax += max(fMax[l][j], fMax[r+1-(1 << j)][j])

print(ansMin, ansMax, end=' ')
