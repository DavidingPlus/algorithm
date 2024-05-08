/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 按照遍历的方式填入值即可
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        ret.resize(n);
        for (auto& row : ret)
            row.resize(n);

        int up = 0, down = n - 1, left = 0, right = n - 1;

        int count = 0;
        while (1) {
            // 向右
            for (int j = left; j <= right; ++j, ++count)
                ret[up][j] = 1 + count;
            // 因为结束肯定是在到达边界的时候结束，所以我在这里做判断
            if (n * n == count)
                break;
            ++up;
            // 向下
            for (int i = up; i <= down; ++i, ++count)
                ret[i][right] = 1 + count;
            if (n * n == count)
                break;
            --right;
            // 向左
            for (int j = right; j >= left; --j, ++count)
                ret[down][j] = 1 + count;
            if (n * n == count)
                break;
            --down;
            // 向上
            for (int i = down; i >= up; --i, ++count)
                ret[i][left] = 1 + count;
            if (n * n == count)
                break;
            ++left;
        }

        return ret;
    }
};
// @lc code=end
