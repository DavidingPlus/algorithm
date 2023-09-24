/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 这个题的思路是：我们遍历这个图，遇到陆地，我们就想办法把他周围连接的所有陆地全部给变成海水，这样在后续的遍历当中就不会出现重复，直到遍历完毕
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ('1' == grid[i][j]) {
                    ++count;
                    dfs(grid, i, j);  // 深度优先进行填充
                    // bfs(grid, i, j);  // 广度优先进行填充
                }

        return count;
    }

    void bfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        // 我们把他上下左右的元素看作结点，满足条件的我们加入队列，然后依次变为0
        // 我们在取出这个节点的时候就把这个节点变为0，这样后面的结点在找的时候就不会重复添加，因为碰到了0
        queue<pair<int, int>> q;
        q.push({x, y});
        // 将本处置为0
        grid[x][y] = '0';

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front();
                int _x = cur.first, _y = cur.second;

                // 判断上下左右四个方向是否可以加入队列
                // 在加入的时候就置为0，因为这样依次可以置很多个0，时间会比取出的时候快，那个就超时了
                if (_x - 1 >= 0 && '1' == grid[_x - 1][_y]) {
                    q.push({_x - 1, _y});
                    grid[_x - 1][_y] = '0';
                }

                if (_x + 1 < m && '1' == grid[_x + 1][_y]) {
                    q.push({_x + 1, _y});
                    grid[_x + 1][_y] = '0';
                }
                if (_y - 1 >= 0 && '1' == grid[_x][_y - 1]) {
                    q.push({_x, _y - 1});
                    grid[_x][_y - 1] = '0';
                }
                if (_y + 1 < n && '1' == grid[_x][_y + 1]) {
                    q.push({_x, _y + 1});
                    grid[_x][_y + 1] = '0';
                }

                q.pop();
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        // 越界返回
        if ((x < 0 || x >= m) || (y < 0 || y >= n))
            return;

        // 为0返回
        if ('0' == grid[x][y])
            return;

        // 这里用深度优先，递归的把上下左右的所有的全部变为0
        // 最好不要使用连续小于符号，因为会出问题
        if ((x >= 0 && x < m) && (y >= 0 && y < n) && ('1' == grid[x][y])) {
            grid[x][y] = '0';
            dfs(grid, x - 1, y);
            dfs(grid, x + 1, y);
            dfs(grid, x, y - 1);
            dfs(grid, x, y + 1);
        }
    }
};
// @lc code=end
