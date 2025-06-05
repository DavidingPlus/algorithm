# 多重背包问题 1
# https://www.acwing.com/problem/content/description/4/

# 稍微优化一点，将 si 件 i 类物品，看成 i 个一模一样的单个物品，因此这个多重背包问题就转化为了 01 背包

N, V = map(int, input().split())

v_pre = [0 for _ in range(1+N)]
w_pre = [0 for _ in range(1+N)]
s = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    v_pre[i], w_pre[i], s[i] = map(int, input().split())

v, w = [0], [0]  # v 和 w 坐标从 1 开始
for i in range(1, 1+N):
    for _ in range(s[i]):
        v.append(v_pre[i])
        w.append(w_pre[i])


N = len(v)-1  # 注意新的 N 的取值，需要扣除掉开头的 0 下标的占位
dp = [[0 for _ in range(1+V)] for _ in range(1+N)]

for i in range(1, 1+N):
    for j in range(1+V):
        dp[i][j] = dp[i-1][j]
        if j >= v[i]:
            dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i])

print(dp[N][V])
