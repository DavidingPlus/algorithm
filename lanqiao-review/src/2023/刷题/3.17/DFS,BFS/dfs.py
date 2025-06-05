# 访问函数
def visit(node: int, vis) -> None:
    print(node, end=" ")
    vis[node] = True
    return


# 深搜
def dfs(start, graph, vis):
    # 从第一个点start开始搜索，搜索过的点用True在vis数组里表示
    visit(start, vis)
    for sub in graph[start]:
        if not vis[sub]:
            dfs(sub, graph, vis)


n = 7
# 图的边数据
data = [
    [1, 0],
    [1, 2],
    [1, 3],
    [1, 6],
    [2, 0],
    [0, 6],
    [3, 6],
    [3, 4],
    [0, 5],
    [5, 6],
    [5, 3],
    [5, 4],
]

# 构建邻接表
n_node = 7
# 这个序列下标表示点，元素代表与这个点相连的点的编号(从0开始)
graph = [[] for i in range(n_node)]
for edge in data:
    graph[edge[0]].append(edge[1])
    graph[edge[1]].append(edge[0])
# print(graph)

print("深搜dfs")
dfs(0, graph, list(False for i in range(n)))

# 运行结果：
# 深搜dfs
# 0 1 2 3 6 5 4
