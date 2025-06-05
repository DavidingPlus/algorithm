# 01 背包
# https://www.acwing.com/problem/content/description/2/

N, V = map(int, input().split())

v = [0 for _ in range(1+N)]
w = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    v[i], w[i] = map(int, input().split())


# dp 表示合理使用前 i 个物品，背包最大容量为 j 的最大价值
dp = [[0 for _ in range(1+V)] for _ in range(1+N)]

for i in range(1, 1+N):
    for j in range(1+V):
        # 注意一点，背包可能本身就是不能装 j 的，也是为了保证数组不越界
        dp[i][j] = dp[i-1][j]
        if j >= v[i]:  # >= 不要写成 > 了，不然很可能少一个取最大值判断
            dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i])

print(dp[N][V])
