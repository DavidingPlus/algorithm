/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color)
    {
        // 这个题目显然使用广度优先算法 BFS
        int m = image.size(), n = image[0].size();

        std::vector<std::vector<bool>> isVisited;
        isVisited.resize(m);
        for (int i = 0; i < m; ++i)
        {
            isVisited[i].resize(n);
            std::fill(isVisited[i].begin(), isVisited[i].end(), false);
        }

        std::queue<std::pair<int, int>> q;

        q.push({sr, sc});
        int target = image[sr][sc];
        image[sr][sc] = color;
        isVisited[sr][sc] = true;

        std::vector<std::pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (false == q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto point = q.front();
                q.pop();

                for (auto &dir : dirs)
                {
                    int newX = point.first + dir.first,
                        newY = point.second + dir.second;
                    if (newX >= 0 and newX < m and newY >= 0 and newY < n and false == isVisited[newX][newY] and target == image[newX][newY])
                    {
                        q.push({newX, newY});
                        image[newX][newY] = color;
                        isVisited[newX][newY] = true;
                    }
                }
            }
        }
        return image;
    }
};
// @lc code=end
