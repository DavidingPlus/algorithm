#
# @lc app=leetcode.cn id=695 lang=python3
#
# [695] 岛屿的最大面积
#

# @lc code=start
from collections import deque


class Solution:
    def maxAreaOfIsland(self, grid: list) -> int:
        m, n = len(grid), len(grid[0])
        isVisited = [[False for _ in range(n)]for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if 1 == grid[i][j] and False == isVisited[i][j]:
                    ans = max(ans, self.getIslandCount(grid, i, j, isVisited))
        return ans

    def getIslandCount(self, grid: list, x: int, y: int, isVisited) -> int:
        # BFS
        m, n = len(grid), len(grid[0])
        ans = 0
        q = deque()

        q.append([x, y])
        isVisited[x][y] = True
        ans += 1

        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while 0 != len(q):
            sz = len(q)
            for _ in range(sz):
                point = q.popleft()

                for dir in dirs:
                    newX, newY = point[0]+dir[0], point[1]+dir[1]
                    if newX >= 0 and newX < m and newY >= 0 and newY < n and 1 == grid[newX][newY] and False == isVisited[newX][newY]:
                        q.append([newX, newY])
                        ans += 1
                        isVisited[newX][newY] = True
        return ans
# @lc code=end
