# 回路计数
# https://www.lanqiao.cn/problems/1462/learning/

from math import gcd

N = 21

# 经典的状压 DP 的问题
# dp[s][j] 表示状态 s 下，最后一次访问 j 的方案数
dp = [[0 for _ in range(N)]for _ in range(1 << N)]
# 初始状态，最开始在第一栋教学楼，所以只用初始这一个值。。。
dp[1][0] = 1

for i in range(1 << N):
    for j in range(N):
        if (1 << j) & i:
            for k in range(N):
                if (1 << k) & (i-(1 << j)):
                    if 1 == gcd(1+j, 1+k):
                        dp[i][j] += dp[i-(1 << j)][k]

print(sum(dp[(1 << N)-1][j] for j in range(N) if 1 == gcd(1, 1+j)))
# print(881012367360)
