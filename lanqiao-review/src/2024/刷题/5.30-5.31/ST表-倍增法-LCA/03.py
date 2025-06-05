# GCD 不小于 k 的子数组
# https://www.lanqiao.cn/problems/3002/learning/

from math import gcd, log2

n, k = map(int, input().split())
nums = list(map(int, input().split()))

# 用 ST 表存储范围内的 gcd
MAX = 1+int(log2(n))
f = [[0 for _ in range(MAX)] for _ in range(n)]

for i in range(n):
    f[i][0] = nums[i]

for j in range(1, MAX):
    for i in range(n):
        if i+(1 << (j-1)) < n:
            f[i][j] = gcd(f[i][j-1], f[i+(1 << (j-1))][j-1])
        else:
            f[i][j] = f[i][j-1]


def get(l, r):
    global f

    j = int(log2(r-l+1))
    return gcd(f[l][j], f[r-(1 << j)+1][j])


ans = 0
for i in range(n):
    left, right = i, n-1

    while left <= right:
        mid = (left+right)//2

        g = get(i, mid)
        if g == k:
            left = 1+mid
        elif g > k:
            left = 1+mid
        else:
            right = mid-1

    if right >= i and get(i, right) >= k:
        ans += right-i+1

print(ans)
