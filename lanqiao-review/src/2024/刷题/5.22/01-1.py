# 组合数 1 （线性 DP + 打表）
# https://www.acwing.com/file_system/file/content/whole/index/content/4412/

MOD = 10**9+7

# 直接算会超时，所以我打个表，也就 2000 的数量级
# 利用公式 C(a, b) == C(a-1, b) + C(a-1, b-1) ，递归会导致炸掉，所以转为迭代
# 题目保证 a >= b
dp = [[0 for _ in range(1+i//2)] for i in range(1+2000)]
dp[1][0] = 1  # a==1 的初始情况

for i in range(2, 1+2000):
    # 这里根据公式，也是只用算到一半即可，不管奇数偶数都是到 i//2 （含）
    # 注意 0==b 和 a==b 不符合这个公式，但是他们的值都是 1 ，因此特殊处理即可
    dp[i][0] = 1
    for j in range(1, 1+i//2):
        # 这里利用了 C(a, b) == C(a, a-b)
        dp[i][j] = (dp[i-1][min(j, (i-1)-j)]
                    + dp[i-1][min(j-1, (i-1)-(j-1))]) % MOD

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    print(dp[a][min(b, a-b)])
