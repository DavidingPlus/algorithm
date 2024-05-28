# GCD 不小于 k 的子数组
# https://www.lanqiao.cn/problems/3002/learning/

from math import log2, gcd

# ST 表加上二分取范围
n, k = map(int, input().split())
nums = list(map(int, input().split()))

MAX = 1+int(log2(n))
f = [[0 for _ in range(MAX)] for _ in range(n)]

for i in range(n):
    f[i][0] = nums[i]

for j in range(1, MAX):
    for i in range(n):
        if i+(1 << (j-1)) >= n:
            f[i][j] = f[i][j-1]
        else:
            f[i][j] = gcd(f[i][j-1], f[i+(1 << (j-1))][j-1])


def get(l, r):
    j = int(log2(r-l+1))
    return gcd(f[l][j], f[r+1-(1 << j)][j])


# 如果暴力枚举所有的子数组，那么应该从某一个点作为左端点开始，暴力枚举右端点，现在我们想办法对其进行优化，计算一个系列的 gcd 的方法从第一个开始，计算第一个和第二个的 gcd ，结果再与第三个计算，以此类推，由于 gcd 的结果必然小于两个数，因此序列越长，计算出的 gcd 就不可能越大，因此这是一个单调不增序列，我们只需要找出大于等于 k 的最右边的端点即可，因此使用二分
ans = 0
for i in range(n):
    # 这是二分求 right_bound 的一个闭区间的模板，由于是递减序列，并且注意循环结束的条件
    l, r = i, n-1

    while l <= r:
        mid = (l+r)//2
        g = get(i, mid)

        if k == g:
            l = 1+mid
        elif k > g:
            r = mid-1
        else:
            l = 1+mid
    # 这里是闭区间，注意用哪个是看相等的时候的逻辑，相等的时候是改变 l ，因此用 r ，并且需要判断最后出来 r 是否符合范围
    if r >= i and get(i, r) >= k:
        ans += r-i+1

print(ans)
