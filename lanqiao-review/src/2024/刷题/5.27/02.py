# 积木画
# https://www.lanqiao.cn/problems/2110/learning/

# TODO 超时 6/20

# 本题写起来不想状压 DP ，但是思路是符合状压 DP 的
# 从左往右填，假设现在要填第 i 列，我们假设前面的列是填满的，那么对于第 i-1 列，如果是 I 型积木最好不过了，这样不会凸出来，如果是 L 型积木，那么会在第 i 列占据上面或者下面一块，不可能把第 i 列占满了，这样前面就会有一个格子的空隙，显然不行
# 因此对于第 i 列来讲，dp[i][j] 表示第 i 列在状态为 j 的方案数，当然对于本题，j 只有三个，全部填满，填充上面，填充下面，具体见 02-递推思路.jpg

MOD = int(1e9) + 7

n = int(input())
dp = [[0 for _ in range(3)] for _ in range(3)]
dp[0][0] = 1
for i in range(1, 1+n):
    # 当前列的索引
    current = i % 3
    # 前一列的索引
    prev = (i - 1) % 3
    # 在前一列的索引
    prev2 = (i - 2) % 3

    dp[current][0] = dp[prev][0]  # 竖着放 1 个 I 形
    dp[current][0] = (dp[current][0] + dp[prev][1]) % MOD  # 放 1 个 L 形
    dp[current][0] = (dp[current][0] + dp[prev][2]) % MOD  # 放 1 个 L 形
    if i >= 2:  # 还有一种特殊情况是在 i-1 和 i 上放两个 I 形
        dp[current][0] = (dp[current][0] + dp[prev2][0]) % MOD

    dp[current][1] = dp[prev][2] % MOD  # 横着放 1 个 I 形
    dp[current][2] = dp[prev][1] % MOD  # 横着放 1 个 I 形
    if i >= 2:  # 同上，在 i-1 和 i 上放 L 形
        dp[current][1] = (dp[current][1] + dp[prev2][0]) % MOD  # 放 1 个 L 形
        dp[current][2] = (dp[current][2] + dp[prev2][0]) % MOD  # 放 1 个 L 形

print(dp[n % 3][0])
