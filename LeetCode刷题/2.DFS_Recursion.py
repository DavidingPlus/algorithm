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
    if 0 == len(graph):
        return []

    isVisited = []
    res = []
    DFS_Recursion(graph, list(graph.keys())[0], isVisited, res)
    return res


# 在 python 中，函数参数如果是 int, bool 这些基础数据类型，那么在函数内部没有办法直接修改入参并返回；但是如果是数据类型比如 list, set, dict 等，这些传递的就是引用 reference，就能够被正确修改
def DFS_Recursion(graph: dict, node: str, isVisited: list, traverseList: list) -> list:
    if node in isVisited:
        return []

    traverseList.append(node)
    isVisited.append(node)
    for e in graph[node]:
        DFS_Recursion(graph, e, isVisited, traverseList)


print(DFS(graph))
