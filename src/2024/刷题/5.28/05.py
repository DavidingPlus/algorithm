# 版本分支
# lca 板子题
# https://www.lanqiao.cn/problems/223/learning/

from math import log2
from sys import setrecursionlimit

setrecursionlimit(int(1e9))

N, Q = map(int, input().split())
# 这里我们的 tree 只存储该节点的子节点，不存储父节点，所以下面的 dfs 会有一定区别
tree = [[] for _ in range(1+N)]
# 维护深度数组
depth = [0 for _ in range(1+N)]
# 维护 ST 表
MAX = 1+int(log2(N))
f = [[0 for _ in range(MAX)] for _ in range(1+N)]

for i in range(N-1):
    u, v = map(int, input().split())
    tree[u].append(v)


def dfs(node: int, prev: int) -> None:
    global tree, depth, f

    f[node][0] = prev
    depth[node] = 1+depth[prev]

    for j in range(1, MAX):
        f[node][j] = f[f[node][j-1]][j-1]

    for child in tree[node]:
        # 这里少了父节点的判断，因为 tree 数组没有存储父节点
        dfs(child, node)


def lca(u: int, v: int) -> bool:
    global tree, depth, f

    # 题目询问 u 是不是 v 的祖先，所以 v 的深度一定大于 u 的深度，否则不是
    if depth[u] > depth[v]:
        return False

    diff = depth[v]-depth[u]
    for j in range(MAX):
        if (1 << j) & diff:
            v = f[v][j]

    return u == v


dfs(1, 0)
for _ in range(Q):
    x, y = map(int, input().split())
    if lca(x, y):
        print("YES")
    else:
        print("NO")
