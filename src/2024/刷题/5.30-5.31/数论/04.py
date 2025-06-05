# 包子凑数
# https://www.acwing.com/problem/content/1228/

from math import gcd

# 包子每笼的个数小于等于 100 个，多个数字的 gcd 只会比两个数更小，不会更大，因此如果有上限值，肯定小于 99 和 100 这俩的上限，即 (99-1)*(100-1)-1 ，因此我的背包上限开 10000 即可
MAX = 10000

N = int(input())
A = [0 for _ in range(N)]
for i in range(N):
    A[i] = int(input())

# 先求出最大公约数
g = A[0]
for i in range(1, N):
    g = gcd(g, A[i])

if 1 != g:
    print("INF")

else:
    # 这就是一个完全背包问题
    A = [0]+A
    dp = [[False for _ in range(MAX)]for _ in range(1+N)]
    # 初始条件不要忘了写，不然后面全是 False
    dp[0][0] = True

    for i in range(1, 1+N):
        for j in range(MAX):
            dp[i][j] = dp[i-1][j]
            if j >= A[i]:
                dp[i][j] = dp[i][j] | dp[i][j - A[i]]

    print(MAX - sum(dp[N]))
