# 区间最大值
# https://www.lanqiao.cn/problems/1205/learning/

from math import sqrt

# 先用分块的思想，复习一下，过了
N, Q = map(int, input().split())
nums = list(map(int, input().split()))

distance = int(sqrt(N))+1
f = [0 for _ in range(N//distance if 0 == N % distance else 1+N//distance)]

# 预处理每个分块的最大值
for i in range(len(f)):
    maxVal = -int(1e9)-1
    for j in range(i*distance, min((i+1)*distance, N)):
        maxVal = max(maxVal, nums[j])
    f[i] = maxVal

for _ in range(Q):
    l, r = map(int, input().split())  # 这两个坐标都是从 1 开始的
    left = (l-1)//distance
    right = (r-1)//distance
    ans = -int(1e9)-1

    # 如果在同一个区间，在该区间中手动计算即可
    if left == right:
        for i in range(l-1, r):
            ans = max(ans, nums[i])
    # 不在同一个区间，首尾的部分手动计算最大值，中间的部分使用 f 数组已经处理好的最大值
    else:
        for i in range(l-1, (left+1)*distance):
            ans = max(ans, nums[i])
        for i in range(1+left, right):
            ans = max(ans, f[i])
        for i in range(right*distance, r):
            ans = max(ans, nums[i])

    print(ans)
