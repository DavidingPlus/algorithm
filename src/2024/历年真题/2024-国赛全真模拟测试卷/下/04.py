# https://www.lanqiao.cn/problems/17117/learning/

# TODO 超时 11/20 ，不过我很满意了
# 经典的 01 背包问题，只不过现在有两个背包，因此开三维即可
N, A, B = map(int, input().split())
w = list(map(int, input().split()))

# dp 代表考虑前 i 个物品，这里的 i 下标从 1 开始，车厢 1 最大容量 j ，车厢 2 最大容量 k 的情况下能运走的最大重量的钢材
# 使用滚动数组优化内存
dp = [[0 for _ in range(1+B)]for _ in range(1+A)]

for i in range(1, 1+N):
    tmp = [[0 for _ in range(1+B)]for _ in range(1+A)]
    for j in range(1+A):
        for k in range(1+B):
            # 不放
            tmp[j][k] = dp[j][k]

            # 放在车厢 1 中
            if j >= w[i-1]:
                tmp[j][k] = max(tmp[j][k], dp[j-w[i-1]][k]+w[i-1])

            # 放在车厢 2 中
            if k >= w[i-1]:
                tmp[j][k] = max(tmp[j][k], dp[j][k-w[i-1]]+w[i-1])
    dp = tmp

print(dp[A][B])
