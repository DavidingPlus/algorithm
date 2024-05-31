# 组合数 1 （线性 DP + 打表）
# https://www.acwing.com/file_system/file/content/whole/index/content/4412/

MOD = int(1e9)+7

# 使用 C(a, b) == C(a-1, b) + C(a-1, b-1) 的公式进行递推
MAX = 2000
dp = [[0 for _ in range(1+i)]for i in range(1+MAX)]

dp[1][0], dp[1][1] = 1, 1

for i in range(2, 1+MAX):
    for j in range(1+i):
        if 0 == j or i == j:
            dp[i][j] = 1
        else:
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]) % MOD

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    print(dp[a][b])
