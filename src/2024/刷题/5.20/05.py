# 李白打酒
# https://www.lanqiao.cn/courses/38752/learning/?id=2546148

N, M = map(int, input().split())
mod = 1000000007

# 定义 dp 数组是遇到店 i 次，花 j 次，酒剩下 k 斗的可能数
# 最后时刻把酒喝光了，因此过程中最大的酒的数量就是 M ，因此酒的上限给 M 即可
# 为了防止下面 1+k 越界，由于 N 和 M 的上限是 110 ，因此数组开 111 的大小，表示从 [0, 110]
dp = [[[0 for _ in range(1+110)]for _ in range(1+110)]for _ in range(1+110)]
dp[0][0][2] = 1

for i in range(1+N):
    for j in range(1+M):
        for k in range(1+M):
            # 上一次可能是花，因此需要保证 j>0 ，即至少遇到花一次
            if j > 0:
                dp[i][j][k] = (dp[i][j][k]+dp[i][j-1][k+1]) % mod
            # 遇到店加倍以后一定是 2 的倍数，因此如果斗数为奇数，上一次一定不可能是店
            # 同理需要保证 i>0
            if i > 0 and False == k & 1:
                dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k//2]) % mod

# 这里需要打印 dp[N][M-1][1] 不能打印 dp[N][M][0] ，因为从整体可能性来讲， dp[N][M][0] 可能从上一次酒的数量为 0 并且这一次遇到店延申过来，但是我们需要契合上一次酒剩下 1 并且遇到花的状态才能正确结束
print(dp[N][M-1][1])
