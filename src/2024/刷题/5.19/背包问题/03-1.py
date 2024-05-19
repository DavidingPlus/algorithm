# 多重背包问题 1
# https://www.acwing.com/problem/content/description/4/

N, V = map(int, input().split())
v = [0 for _ in range(N)]
w = [0 for _ in range(N)]
s = [0 for _ in range(N)]
for i in range(N):
    v[i], w[i], s[i] = map(int, input().split())

# 这个题目的朴素做法就是类似完全背包，只不过每个新物品的使用次数有上限
dp = [[0 for _ in range(1+V)]for _ in range(N)]
for j in range(1+V):
    dp[0][j] = w[0] * min(s[0], j//v[0])

for i in range(1, N):
    for j in range(1+V):
        for k in range(1 + min(s[i], j//v[i])):
            dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*w[i])

print(dp[N-1][V])
