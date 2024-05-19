# 01 背包
# https://www.acwing.com/problem/content/description/2/

N, V = map(int, input().split())
v = [0 for _ in range(N)]
w = [0 for _ in range(N)]
for i in range(N):
    v[i], w[i] = map(int, input().split())

# dp[i][j] 表示使用前 i 件物品，装入最大容量为 j 的背包的最大价值
# 为了展现代码原始逻辑，就不改为滚动数组优化空间复杂度了
dp = [[0 for _ in range(1+V)]for _ in range(N)]
# 填充第一行
for j in range(1+V):
    if j >= v[0]:
        dp[0][j] = w[0]

for i in range(1, N):
    for j in range(1+V):
        if j >= v[i]:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+w[i])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[N-1][V])
