#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#

# @lc code=start
from collections import deque


class Solution:

    def numIslands(self, grid) -> int:
        m, n = len(grid), len(grid[0])
        isVisited = [[False for _ in range(n)]for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if "1" == grid[i][j] and False == isVisited[i][j]:
                    ans += 1
                    self.coverIsland(grid, i, j, isVisited)
        return ans

    # 这个函数用作将 i 和 j 点其他连接的陆地块置为 isVisited，保证岛屿数量正确
    def coverIsland(self, grid: list, x: int, y: int, isVisited: list):
        # BFS
        m, n = len(grid), len(grid[0])
        q = deque()

        q.append([x, y])
        isVisited[x][y] = True

        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while 0 != len(q):
            sz = len(q)
            for _ in range(sz):
                point = q.popleft()

                for dir in dirs:
                    newX, newY = point[0]+dir[0], point[1]+dir[1]
                    if newX >= 0 and newX < m and newY >= 0 and newY < n and "1" == grid[newX][newY] and False == isVisited[newX][newY]:
                        q.append([newX, newY])
                        isVisited[newX][newY] = True
# @lc code=end
