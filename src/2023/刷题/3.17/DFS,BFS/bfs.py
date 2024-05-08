from queue import Queue

# 访问函数
def visit(node: int, vis) -> None:
    print(node, end=" ")
    vis[node] = True
    return


# 广搜
def bfs(start, graph, vis):
    # 访问一个点把一个点放入数队列中
    # 定义一个队列
    queue = Queue()
    # 将首个元素下队列
    # 进队列put 出队列get
    queue.put(start)

    # vis数组不全为真 则还没有访问完毕
    while False in vis:
        # 弹出元素
        node = queue.get()
        if not vis[node]:
            visit(node, vis)
        # 将他的子节点全部下队列
        for sub in graph[node]:
            queue.put(sub)


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
graph = [[] for i in range(n_node)]
for edge in data:
    graph[edge[0]].append(edge[1])
    graph[edge[1]].append(edge[0])


print("广搜bfs")
bfs(0, graph, [False] * n_node)

# 运行结果：
# 广搜bfs
# 0 1 2 6 5 3 4
