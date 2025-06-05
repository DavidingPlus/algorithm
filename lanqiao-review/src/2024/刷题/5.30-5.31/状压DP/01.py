# 星球
# https://www.lanqiao.cn/problems/17136/learning/

from math import sqrt


class node:
    def __init__(self, x: float, y: float, z: float, w: float):
        self.m_x = x
        self.m_y = y
        self.m_z = z
        self.m_w = w


def f(node1: node, node2: node):
    return sqrt((node1.m_x-node2.m_x)**2 + (node1.m_y-node2.m_y)**2 + (node1.m_z-node2.m_z)**2)*node2.m_w


# dp[i][j] 表示在 i 状态下（ i 状态使用二进制表示），最后一次攻击 j 的最小能量
n = int(input())
nodes = [node(0, 0, 0, 0) for _ in range(n)]
for i in range(n):
    l = list(map(float, input().split()))
    nodes[i] = node(l[0], l[1], l[2], l[3])

dp = [[int(1e9) for _ in range(n)]for _ in range(1 << n)]
# 初始状态，从自己出发不消耗能量，这个条件非常重要
for i in range(n):
    dp[1 << i][i] = 0

for i in range(1 << n):
    for j in range(n):
        for k in range(n):
            if (i-(1 << j)) & (1 << k):
                dp[i][j] = min(dp[i][j], dp[i-(1 << j)][k]
                               + f(nodes[k], nodes[j]))

print("{:.2f}".format(min(dp[(1 << n)-1])))
