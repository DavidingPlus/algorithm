# 多重背包问题 1
# https://www.acwing.com/problem/content/description/4/

# 想到了另一种思路，某个体积的多个物品看成多个体积相同的单个物品，用 01 背包的角度解读他们，就可以了
N, V = map(int, input().split())
v_pre = [0 for _ in range(N)]
w_pre = [0 for _ in range(N)]
s = [0 for _ in range(N)]
for i in range(N):
    v_pre[i], w_pre[i], s[i] = map(int, input().split())

v = []
w = []
for i in range(N):
    for _ in range(s[i]):
        v.append(v_pre[i])
        w.append(w_pre[i])

# 后续按照 01 背包的思路来做就行
dp = [0 for _ in range(1+V)]
for j in range(1+V):
    if j >= v[0]:
        dp[j] = w[0]

for i in range(1, len(v)):
    tmp = [0 for _ in range(1+V)]
    for j in range(1+V):
        if j >= v[i]:
            tmp[j] = max(dp[j], dp[j-v[i]]+w[i])
        else:
            tmp[j] = dp[j]
    dp = tmp

print(dp[V])
