# LCA 问题（最近公共祖先）
# https://www.lanqiao.cn/problems/4385/learning/

from math import log2

N = int(input())
# 使用邻接表的方式表示这棵树，下标从 1 开始
tree = [[] for _ in range(1+N)]
# 需要一个深度数组， 0 表示比根节点还要更上层，也就是没有意义
depth = [0 for _ in range(1+N)]

# 为了节省空间， j 的最大值取对数 + 1
MAX = 1+int(log2(N))
# f 数组代表 ST 表，存储父节点信息， 0 表示没有意义，在下面的判断需要注意
f = [[0 for _ in range(MAX)] for _ in range(1+N)]

# 初始化 tree 数组
for _ in range(N-1):
    U, V = map(int, input().split())
    tree[U].append(V)
    tree[V].append(U)


# dfs 函数，预处理 f 数组
def dfs(node: int, prev: int) -> None:
    global tree, depth, f

    # 更新父节点信息
    f[node][0] = prev
    # 更新 depth 数组
    depth[node] = 1+depth[prev]

    # 处理本节点
    for j in range(1, MAX):
        f[node][j] = f[f[node][j-1]][j-1]

    # 递归处理子节点
    for child in tree[node]:
        # 防止遍历父节点导致重复递归
        if prev != child:
            dfs(child, node)


# lca 算法，获得两个点的最近公共祖先
def lca(u: int, v: int) -> int:
    global tree, depth, f

    # 为了处理方便，让 u 节点的深度大于 v 节点的深度
    if depth[u] > depth[v]:
        u, v = v, u

    # 将 u 节点跳转到与 v 节点同一深度的位置（根据是二进制 1），方便开始同时往上跳
    for j in range(MAX):
        if ((depth[u]-depth[v]) >> j) & 1:
            v = f[v][j]

    # 如果直接相等，那么直接返回，在一个点就是另一个点的祖先的时候触发
    if u == v:
        return u

    # 开始真正往上跳，从最大开始，找第一个不是他们祖先的两个点，知道最后把两个节点移动到同一个最近公共祖先的孩子上面，以防止出现找到更高级别祖先的问题
    for j in range(MAX-1, -1, -1):
        # 如果有一个出现 0 ，那么表示越界了
        if 0 == f[u][j] or 0 == f[v][j]:
            continue
        # 开始迭代
        if f[u][j] != f[v][j]:
            u = f[u][j]
            v = f[v][j]

    # 现在这两个点的父节点就是答案
    return f[u][0]


dfs(1, 0)
Q = int(input())
for _ in range(Q):
    u, v = map(int, input().split())
    print(lca(u, v))
