# 单点修改、区间查询（分块）
# https://www.lanqiao.cn/problems/2340/learning/

from math import sqrt

N = int(input())
nums = list(map(int, input().split()))

# 分块的区间长度，为了让算法效率最高，记住一般接近 sqrt(n) 即可 ，为了防止为 0 ，可以取 1+sqrt(n)
distance = 1+int(sqrt(N))
f = [0 for _ in range(N//distance if 0 == N % distance else 1+N//distance)]

# 预处理 f 数组
for i in range(N):
    f[i//distance] += nums[i]

m = int(input())
for _ in range(m):
    l = list(map(int, input().split()))

    if 1 == l[0]:
        f[(l[1]-1)//distance] += l[2]
        nums[l[1]-1] += l[2]
    else:
        left = (l[1]-1)//distance
        right = (l[2]-1)//distance

        ans = 0
        # 如果位于同一个区间，直接暴力计算
        if left == right:
            for i in range(l[1]-1, l[2]):
                ans += nums[i]
        # 中间的完整区间使用 f 数组
        else:
            for i in range(l[1]-1, (1+left)*distance):
                ans += nums[i]
            for i in range(1+left, right):
                ans += f[i]
            for i in range(right*distance, l[2]):
                ans += nums[i]

        print(ans)
