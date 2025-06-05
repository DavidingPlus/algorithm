# -*- coding:utf-8 -*-
# 状态压缩 DP
# https://www.lanqiao.cn/problems/17136/learning/

from math import sqrt
from sys import maxsize

# TODO 超时 14/20 ，不过我很满意了


class node:
    m_x = 0.0
    m_y = 0.0
    m_z = 0.0
    m_w = 0.0

    def __init__(self, x, y, z, w):
        self.m_x, self.m_y, self.m_z, self.m_w = x, y, z, w


def distance(n1: node, n2: node) -> float:
    return sqrt((n1.m_x-n2.m_x)**2+(n1.m_y-n2.m_y)**2+(n1.m_z-n2.m_z)**2)*n2.m_w


# 使用二进制来表示某个状态
# 例如对于 5 个星球， 11100 表示已经攻击前三个星球，这是一个状态，可以延伸出 11101 和 11110 ，我们假设 dp[s] 表示这个状态的最小值，假设对于 11110 而言，代表下一个攻击 4 号星球，但是应该从哪里出发攻击呢？ dp[s] 的状态并没有记录是最后是哪个星球，只知道一个最小值，我们假设是 1 ，在这种情况下，如果 1 号和 4 号相距非常远，加上以后很可能 1 号到 4 号就不是最小值了。那么仅仅有一个最小值是没有办法进行迭代的，因为我们不知道以最后一次攻击是每个星球的最小值，这样没有办法做判断。因此加上一维 dp[s][i] 代表在二进制 s 状态下最后一次攻击的星球是 i 的最小值
# 并且由于 s 用二进制表示，那么之前的状态根据二进制转换成为十进制可知一定是计算出来的，因此没有后效性，完美符合动态规划
n = int(input())
dp = [[maxsize for _ in range(1+n)]for _ in range(1 << n)]
# 初始状态，只有单个星球被攻击的时候，根据题目是不需要能量的，这个初始条件非常重要，因为它并不能从没有星球推导而来，因此需要特殊初始化
for i in range(n):
    dp[1 << i][i] = 0

nodes = []
for i in range(n):
    l = list(map(int, input().split()))
    nodes.append(node(l[0], l[1], l[2], l[3]))


for i in range(1 << n):
    for j in range(n):
        if (1 << j) & i:
            for k in range(n):
                if (1 << k) & (i - (1 << j)):
                    dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] +
                                   distance(nodes[k], nodes[j]))

# 尤其注意 python 运算符的优先级， + - 号高于位运算，所以记得加上括号
print("{:.2f}".format(min(dp[(1 << n)-1])))
