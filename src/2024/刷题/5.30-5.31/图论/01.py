# floyd
# https://www.acwing.com/problem/content/description/856/

n, m, k = map(int, input().split())

dp = [[int(1e9) for _ in range(n)]for _ in range(n)]

# 初始的 dp 数组，就是最初图的邻接矩阵的样子
for _ in range(m):
    x, y, z = map(int, input().split())
    dp[x-1][y-1] = min(dp[x-1][y-1], z)  # 如果有重边，显然取最小值

# 自己到自己的最短路径一定为 0（防止输入的时候加上一个自旋，因此这句代码放在下面）
for i in range(n):
    dp[i][i] = 0

# 依次将每个点 p 作为路径的中间点进行 dp 数组的更新，注意每次都使用现有的 dp 数组计算，不断迭代
for p in range(n):
    for i in range(n):
        for j in range(n):
            # i -> j 分为 i -> k -> j
            # 由于有负权边，因此如果不处理，结果可能会是类似 int(1e9) - 5 这种，会对最后的判断产生干扰，这里处理一下，当然，即使没有负权边，也这么处理一下，是没有错的
            if int(1e9) != dp[i][p] and int(1e9) != dp[p][j]:
                dp[i][j] = min(dp[i][j], dp[i][p]+dp[p][j])

for _ in range(k):
    x, y = map(int, input().split())
    if int(1e9) == dp[x-1][y-1]:
        print("impossible")
    else:
        print(dp[x-1][y-1])
