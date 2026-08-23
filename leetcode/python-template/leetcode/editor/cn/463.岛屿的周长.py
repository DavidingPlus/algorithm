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

        # 显然是广度优先，一个块往外扩散一个，周长变化一定的值
        # 找到第一个非 0 的区域
        x, y = [-1, -1]
        for i in range(m):
            flag = False
            for j in range(n):
                if 1 == grid[i][j]:
                    flag = True
                    x, y = [i, j]
                    break
            if flag:
                break

        if -1 == x and -1 == y:
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
                        # 周长变化，加上新方块周围 not isVisited 的个数，减去 isVisited 的个数；如果新方块已经超出边界，那么应该加 1
                        for dir2 in dirs:
                            newX2, newY2 = newX+dir2[0], newY+dir2[1]
                            if newX2 < 0 or newX2 >= m or newY2 < 0 or newY2 >= n:
                                ans += 1
                            else:
                                ans += 1 if False == isVisited[newX2][newY2] else -1

        return ans

# @lc code=end
