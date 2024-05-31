# 多重背包问题 1
# https://www.acwing.com/problem/content/description/4/

# 朴素做法

N, V = map(int, input().split())

v = [0 for _ in range(1+N)]
w = [0 for _ in range(1+N)]
s = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    v[i], w[i], s[i] = map(int, input().split())

dp = [[0 for _ in range(1+V)] for _ in range(1+N)]

for i in range(1, 1+N):
    for j in range(1+V):
        # 朴素做法，枚举符合当前条件的第 i 个物品的所有的使用个数的情况
        for k in range(1+min(s[i], j//v[i])):
            dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*w[i])

print(dp[N][V])
