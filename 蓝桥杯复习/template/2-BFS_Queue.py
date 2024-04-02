# 参考 blog：https://blog.csdn.net/weixin_45705162/article/details/108296417

# 邻接表
graph = {
    'A': ['B', 'C', 'D'],
    'B': ['A', 'E', 'F'],
    'C': ['A', 'D', 'F', 'G'],
    'D': ['A', 'C', 'G'],
    'E': ['B'],
    'F': ['B', 'C'],
    'G': ['C', 'D']
}


def BFS(graph: dict) -> list:
    if 0 == len(graph):
        return []

    # 使用一个 isVisited 数组记录节点是否被遍历过
    # 联系二叉树的层序遍历，使用队列存储数据，这里也是一样
    res = []
    isVisited = []
    q = [list(graph.keys())[0]]  # 插入第一个节点

    while 0 != len(q):
        # 从队首取出一个节点
        node = q[0]
        q.pop(0)  # 这里队列由于是先进先出，进出的位置不一样，因此这句放在后面也没关系，栈那边就需要注意了
        if node not in isVisited:
            res.append(node)
            isVisited.append(node)

            # 处理与该节点连接的节点
            for e in graph[node]:
                if e not in isVisited:
                    q.append(e)

    return res


print(BFS(graph))
