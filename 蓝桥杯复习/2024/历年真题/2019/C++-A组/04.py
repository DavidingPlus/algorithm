# https://www.lanqiao.cn/problems/602/learning/?page=1&first_category_id=1&name=%E8%BF%B7%E5%AE%AB

from collections import deque

# 测试数据
# 010000
# 000100
# 001001
# 110000
# ans: DRRURRDDDR


# 根据两个坐标，得到 pointBefore 移动到 pointAfter 的方向，内部函数，这两个坐标一定是相邻的且不相等
def getDir(pointBefore: list, pointAfter: list) -> str:
    # 内部函数，这里就不进行其他情况的判断了

    # x 坐标相等
    if pointBefore[0] == pointAfter[0]:
        return 'R' if pointAfter[1] - pointBefore[1] > 0 else 'L'
    # y 坐标相等
    else:
        return 'D' if pointAfter[0] - pointBefore[0] > 0 else 'U'


# 目前思路：为了考虑最短路径以及字典序最小，使用广度优先搜索
# 如何记录方向呢？在 isVisited 数组中在存储一个上一个到达的方向，当计算到终点的时候在反推回去即可
f = open("./04.txt", mode="r", encoding="utf-8")
# 读取 graph
graph = []
while True:
    s = f.readline()
    if "" == s:
        break
    if "\n" == s[len(s)-1]:
        s = s[:-1]
    graph.append(s)
f.close()

# 使用广度优先计算最短路径
m, n = len(graph), len(graph[0])
q = deque()
isVisited = [[[False,
               [-1, -1]]
              for _ in range(n)]
             for _ in range(m)]  # 第二个参数存储父节点的坐标

# 压入起点（填空题，不考虑起点终点为障碍物的情况）
q.append([0, 0])
isVisited[0][0] = [True, [0, 0]]

dirs = [[1, 0], [0, -1], [0, 1], [-1, 0]]  # 对应 D L R U，字典序从小到大
while 0 != len(q):
    sz = len(q)
    flag = False

    for _ in range(sz):
        node = q.popleft()
        x, y = node[0], node[1]

        if m - 1 == x and n - 1 == y:
            flag = True
            break

        for dir in dirs:
            newX, newY = x+dir[0], y+dir[1]
            if newX >= 0 and newX < m and newY >= 0 and newY < n and '0' == graph[newX][newY] and False == isVisited[newX][newY][0]:
                q.append([newX, newY])
                isVisited[newX][newY] = [True, [x, y]]

    if flag:
        break

# 回溯计算步数
ans = str()
x, y = m-1, n-1
while not (0 == x and 0 == y):
    ans = getDir(isVisited[x][y][1], [x, y]) + ans
    x, y = isVisited[x][y][1]
print(ans)
# print("DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR")
