# LCA 问题（最近公共祖先）
# https://www.lanqiao.cn/problems/4385/learning/

from math import log2
from sys import setrecursionlimit
setrecursionlimit(int(1e8))

N = int(input())
tree = [[] for _ in range(1+N)]  # 节点编号从 1 开始
depth = [0 for _ in range(1+N)]

MAX = 1+int(log2(N))
f = [[0 for _ in range(MAX)]
     for _ in range(1+N)]  # 结果为 0 代表当前 f[i][j] 的祖先节点不存在

for _ in range(N-1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)


# 预处理 f 数组
def dfs(node, prev):
    global tree, depth, f

    depth[node] = 1+depth[prev]

    f[node][0] = prev
    for j in range(1, MAX):
        f[node][j] = f[f[node][j-1]][j-1]

    for child in tree[node]:
        # 在 tree 数组存储的是所有和当前节点相连的点，因此没有做唯一父节点的区分，需要判断一下
        if child != prev:
            dfs(child, node)


def lca(u, v):
    global tree, depth, f

    # 首先需要将两个节点拉到统一深度，为了方便处理，让 u 的深度大于 v 的深度
    if depth[u] < depth[v]:
        u, v = v, u

    # 按照二进制的表示依次往上跳
    diff = depth[u]-depth[v]
    for j in range(MAX):
        if (1 << j) & diff:
            u = f[u][j]

    # 如果一个节点是另一个节点的祖先节点，那么跳完以后 u == v
    if u == v:
        return u

    # 不是，位于结果的不同子树中，开始查询
    # 记住这个思路：从最大开始，找第一个不是他们祖先的两个点，直到最后把两个节点移动到同一个最近公共祖先的孩子上面，以防止出现找到更高级别祖先的问题。我模拟过，这样确实是对的，但是我给不出严密的数学证明，记住这个思路即可
    # 这里只有一重循环是因为， j 是从大往小递推的，本次网上跳跃以后，下一次跳跃必然是小于这个 j 值的，不然就会跳到更到的位置，与我们最终的目的最近公共祖先的子节点就背道而驰了，因此这里优化为一重循环
    for j in range(MAX-1, -1, -1):
        if 0 == f[u][j] or 0 == f[v][j]:
            continue

        if f[u][j] != f[v][j]:
            u = f[u][j]
            v = f[v][j]

    return f[u][0]


dfs(1, 0)
Q = int(input())
for _ in range(Q):
    A, B = map(int, input().split())
    print(lca(A, B))
