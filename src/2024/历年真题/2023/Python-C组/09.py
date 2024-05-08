# https://www.lanqiao.cn/problems/3533/learning/?subject_code=3&group_code=3&match_num=14&match_flow=1&origin=cup

# 首先关于取反，每次取反加 1 ，最后奇数表示黑色，偶数表示白色（最开始为白色）
n, m = map(int, input().split(' '))
op = []
for i in range(m):
    op.append(list(map(int, input().split(' '))))

# 二维差分数组，数据从下标 1 开始
vec = [[0] * (2 + n) for _ in range(2 + n)]
for e in op:
    x1 = e[0]
    y1 = e[1]
    x2 = e[2]
    y2 = e[3]

    # 这个地方的逻辑自己画个图就明白了，为了防止越界，开了 2 + n 的矩阵数组
    vec[x1][y1] += 1
    # 其他地方再加 1 ，表示不翻
    vec[1 + x2][y1] += 1
    vec[x1][1 + y2] += 1
    # 交叉处重复了，再加 1 ，表示不翻
    vec[1 + x2][1 + y2] += 1


# 计算前缀和即为答案
preSum = [[0] * (2 + n) for _ in range(2 + n)]
for i in range(1, 1 + n):
    for j in range(1, 1 + n):
        preSum[i][j] = vec[i][j] + preSum[i - 1][j] + \
            preSum[i][j - 1] - preSum[i - 1][j - 1]
        if j != n:
            print(preSum[i][j] % 2, end='')
        else:
            print(preSum[i][j] % 2)
