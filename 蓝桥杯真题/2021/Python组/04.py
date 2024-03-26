# https://www.lanqiao.cn/problems/1460/learning/?page=1&first_category_id=1&name=%E8%B7%AF%E5%BE%84

import sys
import math


def icm(a, b):
    return a*b // math.gcd(a, b)


# 动态规划的问题
n = 2021

# 获取 int 的最大值，最小值就是取反再减去 1
# 获取 float 的 最大值
# max_float=float('inf')
dp = [sys.maxsize]*(n+1)
# 明确初始状态
dp[1] = 0

# 虽然答案是对的，但是个人思考感觉有个地方，新加入的节点可能会反过来影响旧节点的最短距离
# 3.26 跟新：
# 1. 首先对于 2 ~ 22 号，他们到 1 的最短路径一定是直接到达 1 ，因为由于边长是最小公倍数，一定大于等于该节点的值，走弯路必然就更长了
# TODO 2. 对于后面的节点，我暂时不知道。。。
for i in range(2, n+1):
    for j in range(1, i):
        if abs(i-j) <= 21:
            dp[i] = min(dp[i], icm(i, j)+dp[j])
print(dp[n])
