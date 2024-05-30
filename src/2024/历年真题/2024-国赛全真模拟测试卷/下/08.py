# https://www.lanqiao.cn/problems/18427/learning/

n = int(input())

# 所有的字符串都是按照顺序进行拼接的，所以对于第 i 根字符串，只有选择放与不放两种情况，这两种情况各自有分别依赖于再上一根字符串的状态，状态转移方程就出来了
dp = [[1+2*n for _ in range(2)] for _ in range(n)]

sl = ["" for _ in range(n)]
for i in range(n):
    sl[i] = input()

dp[0] = [2, 2]
for i in range(1, n):
    # 1. 第 i 个字符串不翻转，并且 i-1 不翻转
    if sl[i-1][1] == sl[i][0]:
        dp[i][0] = min(dp[i][0], 1+dp[i-1][0])
    else:
        dp[i][0] = min(dp[i][0], 2+dp[i-1][0])

    # 2. 第 i 个字符串不翻转，并且 i-1 翻转
    if sl[i-1][0] == sl[i][0]:
        dp[i][0] = min(dp[i][0], 1+dp[i-1][1])
    else:
        dp[i][0] = min(dp[i][0], 2+dp[i-1][1])

    # 3. 第 i 个字符串翻转，并且 i-1 不翻转
    if sl[i-1][1] == sl[i][1]:
        dp[i][1] = min(dp[i][1], 1+dp[i-1][0])
    else:
        dp[i][1] = min(dp[i][1], 2+dp[i-1][0])

    # 3. 第 i 个字符串翻转，并且 i-1 翻转
    if sl[i-1][0] == sl[i][1]:
        dp[i][1] = min(dp[i][1], 1+dp[i-1][1])
    else:
        dp[i][1] = min(dp[i][1], 2+dp[i-1][1])

print(min(dp[n-1]))
