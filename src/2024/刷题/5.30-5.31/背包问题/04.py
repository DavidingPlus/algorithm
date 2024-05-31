# 分组背包
# https://www.acwing.com/problem/content/description/9/

N, V = map(int, input().split())
v = [[] for _ in range(1+N)]
w = [[] for _ in range(1+N)]

for i in range(1, 1+N):
    cnt = int(input())
    for j in range(cnt):
        vij, wij = map(int, input().split())
        v[i].append(vij)
        w[i].append(wij)

dp = [[0 for _ in range(1+V)]for _ in range(1+N)]
for i in range(1, 1+N):
    for j in range(1+V):
        dp[i][j] = dp[i-1][j]
        # 各自处理组内的物品即可
        for k in range(len(v[i])):
            if j - v[i][k] >= 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j - v[i][k]]+w[i][k])

print(dp[N][V])
