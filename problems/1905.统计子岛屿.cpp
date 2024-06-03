/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution
{
public:
    int countSubIslands(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2)
    {
        // 如果 grid2 中的每个岛屿部分的每个点都在 grid1 中都是岛屿子块，那么对应的岛屿部分一定是子岛屿
        int m = grid1.size(), n = grid1[0].size();
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
                if (1 == grid2[i][j] && false == isVisited[i][j])
                {
                    if (isSubIslandDFS(grid1, grid2, i, j, isVisited))
                    {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }

    bool isSubIslandDFS(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2, int x, int y, std::vector<std::vector<bool>> &isVisited)
    {
        int m = grid1.size(), n = grid1[0].size();
        bool res = true;
        if (0 == grid1[x][y])
        {
            isVisited[x][y] = true; // 这里不能直接 return 掉，因为需要递归遍历这一块岛屿修改 isVisited 数组，防止重复遍历
            res = false;
        }

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dirs[i][0], newY = y + dirs[i][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && 1 == grid2[newX][newY] && false == isVisited[newX][newY])
            {
                isVisited[newX][newY] = true;
                res &= isSubIslandDFS(grid1, grid2, newX, newY, isVisited);
            }
        }
        return res;
    }
};
// @lc code=end
