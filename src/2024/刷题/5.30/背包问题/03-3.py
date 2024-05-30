# 多重背包问题 2: 二进制优化
# https://www.acwing.com/problem/content/description/5/

# 二进制优化
# 1 2 4 8 能表示出 [1, 15] 之间所有的数，并且只是用这四个数一次就能表示出来；然后考虑 13 ，如果拆分成为 1 2 4 6 ，前三个数能表示出 [1, 7] ，加上 6 就能表示出 [7, 13] 了，这样能把所有的物品按照二进制的方式重新分配，能保证最多使用这些物品一次就能够表示出原有物品上限的个数，当然这些物品的 v 和 w 都翻倍，这样就转化为了 01 背包问题

N, V = map(int, input().split())

v_pre = [0 for _ in range(1+N)]
w_pre = [0 for _ in range(1+N)]
s = [0 for _ in range(1+N)]
for i in range(1, 1+N):
    v_pre[i], w_pre[i], s[i] = map(int, input().split())

v, w = [0], [0]
for i in range(1, 1+N):
    cnt = s[i]
    base = 1
    # 取 > 保证 7 = 1 + 2 + 4 这种不多余的，在 4 跳出循环； 13 = 1 + 2 + 4 + 6 在 6 跳出循环，这样循环结束 cnt > 0 ，作最后一次插入即可
    while cnt > base:
        v.append(base*v_pre[i])
        w.append(base*w_pre[i])
        cnt -= base
        base *= 2

    v.append(cnt*v_pre[i])
    w.append(cnt*w_pre[i])

N = len(v)-1
dp = [[0 for _ in range(1+V)] for _ in range(1+N)]

for i in range(1, 1+N):
    for j in range(1+V):
        dp[i][j] = dp[i-1][j]
        if j >= v[i]:
            dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i])

print(dp[N][V])
