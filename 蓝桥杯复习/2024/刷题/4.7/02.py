# https://www.lanqiao.cn/problems/2410/learning/?page=1&first_category_id=1&second_category_id=3&tags=2023

from collections import deque

file = open("./02.txt", encoding="utf-8", mode='r')
grid = []
while True:
    s = file.readline()
    if "" == s:
        break
    if '\n' == s[len(s)-1]:
        s = s[:-1:]
    grid.append(s)
file.close()


# 新进入一个区块，将周围的临近区域全部填满，返回这个区块的大小
def coverIslandAround(grid, isVisited, x, y):
    res = 0
    q = deque()
    q.append([x, y])
    isVisited[x][y] = True
    res += 1

    dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    while 0 != len(q):
        sz = len(q)
        for _ in range(sz):
            node = q.popleft()

            for dir in dirs:
                newX, newY = node[0]+dir[0], node[1]+dir[1]

                if newX >= 0 and newX < m and newY >= 0 and newY < n and False == isVisited[newX][newY] and "1" == grid[newX][newY]:
                    q.append([newX, newY])
                    isVisited[newX][newY] = True
                    res += 1
    return res


# 广搜，然后更改 isVisited 数组
ans = 0
m, n = len(grid), len(grid[0])
isVisited = [[False for _ in range(n)] for _ in range(m)]


for i in range(m):
    for j in range(n):
        if "1" == grid[i][j] and False == isVisited[i][j]:
            ans = max(ans, coverIslandAround(grid, isVisited, i, j))

print(ans)
# print(148)
