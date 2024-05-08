/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution
{
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<bool>> isVisited;
        isVisited.resize(m);
        for (int i = 0; i < m; ++i)
        {
            isVisited[i].resize(n);
            std::fill(isVisited[i].begin(), isVisited[i].end(), false);
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                if (1 == grid[i][j] and false == isVisited[i][j])
                {
                    ans = std::max(ans, getIslandSizeDFS(grid, i, j, isVisited)); // DFS
                    // ans = std::max(ans, getIslandSizeBFS(grid, i, j, isVisited)); // BFS
                }
            }
        }
        return ans;
    }

    // 深度优先（递归，懒得写迭代了）
    int getIslandSizeDFS(std::vector<std::vector<int>> &grid, int x, int y, std::vector<std::vector<bool>> &isVisited)
    {
        int m = grid.size(), n = grid[0].size();
        isVisited[x][y] = true;
        int res = 1;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dirs[i][0], newY = y + dirs[i][1];
            if (newX >= 0 and newX < m and newY >= 0 and newY < n and 1 == grid[newX][newY] and false == isVisited[newX][newY])
            {
                isVisited[newX][newY] = true;
                res += getIslandSizeDFS(grid, newX, newY, isVisited);
            }
        }
        return res;
    }

    // 广度优先
    int getIslandSizeBFS(std::vector<std::vector<int>> &grid, int x, int y, std::vector<std::vector<bool>> &isVisited)
    {
        int m = grid.size(), n = grid[0].size();
        int res = 1;

        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        isVisited[x][y] = true;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (false == q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto point = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int newX = point.first + dirs[i][0], newY = point.second + dirs[i][1];
                    if (newX >= 0 and newX < m and newY >= 0 and newY < n and 1 == grid[newX][newY] and false == isVisited[newX][newY])
                    {
                        ++res;
                        q.push({newX, newY});
                        isVisited[newX][newY] = true;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end
