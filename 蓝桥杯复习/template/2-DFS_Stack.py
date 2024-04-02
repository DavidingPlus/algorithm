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


def DFS(graph: dict) -> list:
    # 不使用递归的方式处理，使用迭代的栈进行处理
    if 0 == len(graph):
        return []

    res = []
    isVisited = []
    s = [list(graph.keys())[0]]

    while 0 != len(s):
        node = s[len(s)-1]
        s.pop(len(s)-1)  # 栈先进后出，进出的口一样，所以这里需要先弹掉
        if node not in isVisited:
            res.append(node)
            isVisited.append(node)

            for e in graph[node]:
                if e not in isVisited:
                    s.append(e)
    return res


print(DFS(graph))
