#
# @lc app=leetcode.cn id=463 lang=python3
#
# [463] 岛屿的周长
#

# @lc code=start
from collections import deque


class Solution:
    def islandPerimeter(self, grid) -> int:
        m, n = len(grid), len(grid[0])

        # 显然是广度优先，一个块往外扩散一个，周长加 2
        # TODO：初步逻辑是这样，但是有问题
        # 找到第一个非 0 的区域
        x, y = [0, 0]
        for i in range(m):
            for j in range(n):
                if 1 == grid[i][j]:
                    x, y = [i, j]
                    break

        if 0 == x and 0 == y:
            return 0

        # BFS
        isVisited = [[False for _ in range(n)]for _ in range(m)]
        q = deque()
        q.append([x, y])
        isVisited[x][y] = True
        ans = 4

        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while 0 != len(q):
            sz = len(q)
            for _ in range(sz):
                point = q.popleft()

                for dir in dirs:
                    newX, newY = point[0]+dir[0], point[1]+dir[1]
                    if newX >= 0 and newX < m and newY >= 0 and newY < n and 1 == grid[newX][newY] and False == isVisited[newX][newY]:
                        q.append([newX, newY])
                        isVisited[newX][newY] = True
                        ans += 2
        return ans

# @lc code=end
