# 一个多重背包的问题变式
# https://www.lanqiao.cn/problems/1177/learning/

# 超时了 4/9 ，在 05-2.py 中尝试进行了优化
N, V = map(int, input().split())
w = [0 for _ in range(N)]
v = [0 for _ in range(N)]
s = [0 for _ in range(N)]
for i in range(N):
    w[i], v[i], s[i] = map(int, input().split())

# 这个题目的朴素做法就是类似完全背包，只不过每个新物品的使用次数有上限
dp = [[0 for _ in range(1+V)]for _ in range(N)]
for j in range(1+V):
    if 0 == s[0]:  # 注意区别： 0==s[i] 表示无限个
        dp[0][j] = v[0] * (j//w[0])
    else:
        dp[0][j] = v[0] * min(s[0], j//w[0])

for i in range(1, N):
    for j in range(1+V):
        top = 1 + (j//w[i]) if 0 == s[i] else 1 + min(s[i], j//w[i])
        for k in range(top):
            dp[i][j] = max(dp[i][j], dp[i-1][j-k*w[i]]+k*v[i])

print(dp[N-1][V])
