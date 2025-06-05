#
# @lc app=leetcode.cn id=1254 lang=python3
#
# [1254] 统计封闭岛屿的数目
#

# @lc code=start
from collections import deque


class Solution:

    def closedIsland(self, grid) -> int:
        m, n = len(grid), len(grid[0])
        isVisited = [[False for _ in range(n)]for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if 0 == grid[i][j] and False == isVisited[i][j]:
                    if self.coverIsland(grid, i, j, isVisited):
                        ans += 1
        return ans

    # 这个函数用作将 i 和 j 点其他连接的陆地块置为 isVisited，保证岛屿数量正确，并且返回这个函数是不是封闭岛，即有没有陆地位于数组边界上
    def coverIsland(self, grid: list, x: int, y: int, isVisited: list):
        # BFS
        res = True
        m, n = len(grid), len(grid[0])
        q = deque()

        q.append([x, y])
        isVisited[x][y] = True
        if 0 == x or m-1 == x or 0 == y or n-1 == y:
            res = False

        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while 0 != len(q):
            sz = len(q)
            for _ in range(sz):
                point = q.popleft()

                for dir in dirs:
                    newX, newY = point[0]+dir[0], point[1]+dir[1]
                    if newX >= 0 and newX < m and newY >= 0 and newY < n and 0 == grid[newX][newY] and False == isVisited[newX][newY]:
                        q.append([newX, newY])
                        isVisited[newX][newY] = True
                        if 0 == newX or m-1 == newX or 0 == newY or n-1 == newY:
                            res = False
        return res

# @lc code=end
