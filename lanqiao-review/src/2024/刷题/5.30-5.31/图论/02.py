import sys
sys.setrecursionlimit(int(1e8))


# 弗洛伊德算法
def floyd():
    n = len(graph)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
                    # parents 存储的是当前节点的前驱节点，因此 i -> k -> j 如果需要被修改的话，那么更新以后的 j 的前驱节点就是 parents 数组中记录的 k -> j 的前驱节点
                    parents[i][j] = parents[k][j]  # 更新父结点


# 打印路径，递归打印即可
def print_path(i, j):
    if i != j:
        print_path(i, parents[i][j])
    print(j, end='-->')


# Data [u, v, cost]
datas = [
    [0, 1, 2],
    [0, 2, 6],
    [0, 3, 4],
    [1, 2, 3],
    [2, 0, 7],
    [2, 3, 1],
    [3, 0, 5],
    [3, 2, 12],
]

n = 4

# 无穷大
inf = 9999999999

# 构图
graph = [[(lambda x: 0 if x[0] == x[1] else inf)([i, j])
          for j in range(n)] for i in range(n)]
parents = [[i] * n for i in range(4)]  # 关键地方，i-->j 的父结点初始化都为i
for u, v, c in datas:
    graph[u][v] = c  # 因为是有向图，边权只赋给graph[u][v]
    # graph[v][u] = c # 如果是无向图，要加上这条。

floyd()

print('Costs:')
for row in graph:
    for e in row:
        print('∞' if e == inf else e, end='\t')
    print()

print('\nPath:')
for i in range(n):
    for j in range(n):
        print('Path({}-->{}): '.format(i, j), end='')
        print_path(i, j)
        print(' cost:', graph[i][j])

# 最终的graph
# graph[i][j]表示i-->j的最短路径
# 0	 2	5	4
# 9	 0	3	4
# 6	 8	0	1
# 5	 7	10	0
#
# Path:
# Path(0-->0): 0--> cost: 0
# Path(0-->1): 0-->1--> cost: 2
# Path(0-->2): 0-->1-->2--> cost: 5
# Path(0-->3): 0-->3--> cost: 4
# Path(1-->0): 1-->2-->3-->0--> cost: 9
# Path(1-->1): 1--> cost: 0
# Path(1-->2): 1-->2--> cost: 3
# Path(1-->3): 1-->2-->3--> cost: 4
# Path(2-->0): 2-->3-->0--> cost: 6
# Path(2-->1): 2-->3-->0-->1--> cost: 8
# Path(2-->2): 2--> cost: 0
# Path(2-->3): 2-->3--> cost: 1
# Path(3-->0): 3-->0--> cost: 5
# Path(3-->1): 3-->0-->1--> cost: 7
# Path(3-->2): 3-->0-->1-->2--> cost: 10
# Path(3-->3): 3--> cost: 0
