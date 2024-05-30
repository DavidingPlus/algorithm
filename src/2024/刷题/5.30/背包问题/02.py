# 完全背包
# https://www.acwing.com/problem/content/description/3/

N, V = map(int, input().split())

v = [0 for _ in range(1+N)]
w = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    v[i], w[i] = map(int, input().split())

dp = [[0 for _ in range(1+V)] for _ in range(1+N)]

for i in range(1, 1+N):
    for j in range(1+V):
        dp[i][j] = dp[i-1][j]
        if j >= v[i]:
            # 与 01 背包的区别就在于第二个是 i 不是 i-1
            dp[i][j] = max(dp[i][j], dp[i][j-v[i]]+w[i])

print(dp[N][V])
