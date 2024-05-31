# 区间最大值
# https://www.lanqiao.cn/problems/1205/learning/

from math import log2

N, Q = map(int, input().split())
nums = list(map(int, input().split()))

# f[i][j] 代表从 i 下标的元素开始，长度为 2**j 的区间的最大值
MAX = 1+int(log2(N))
f = [[0 for _ in range(MAX)]for _ in range(N)]

# 预处理 f 数组
for i in range(N):
    f[i][0] = nums[i]

# 根据递推公式，知道 f[i][j] 依赖于 j-1 列的元素，并且行号还比 i 大，因此先遍历 j
for j in range(1, MAX):
    for i in range(N):
        # 保证不要越界
        if i+(1 << (j-1)) < N:
            f[i][j] = max(f[i][j-1], f[i+(1 << (j-1))][j-1])
        else:
            f[i][j] = f[i][j-1]

for _ in range(Q):
    l, r = map(int, input().split())  # 注意 l r 从 1 开始的，我们的数组都是从 0 开始
    j = int(log2(r-l+1))
    print(max(f[l-1][j], f[(r-1)-(1 << j)+1][j]))
