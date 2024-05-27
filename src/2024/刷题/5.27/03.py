# 小明的宠物袋
# https://www.lanqiao.cn/problems/1261/learning/

N, M = map(int, input().split())

a = [[0 for _ in range(M)]for _ in range(N)]
for i in range(N):
    a[i] = list(map(int, input().split()))

# dp 数组表示处理到第 i 行，状态为 j 的个数， i 从 1 开始
dp = [[0 for _ in range(1 << M)]for _ in range(1+N)]

ans = 0
for i in range(1, 1+N):
    for j in range(1 << M):
        # 判断该状态是否自己存在相邻的两个 1
        if j & (j >> 1):
            continue

        # 判断当前状态是否占据食物的格子
        flag = False
        for k in range(M):
            if 1 == a[i-1][k] and (j >> k) & a[i-1][k]:
                flag = True
                break
        if flag:
            continue

        # 依次枚举上一行的所有状态，并且判断是否和当前状态有上下相邻的两个 1
        for k in range(1 << M):
            if j & k:
                continue

            # 计算当前状态有多少个 1
            cnt = 0
            tmp = j
            while tmp > 0:
                if tmp & 1:
                    cnt += 1
                tmp >>= 1

            dp[i][j] = max(dp[i][j], dp[i-1][k]+cnt)

        ans = max(ans, dp[i][j])

print(ans)
