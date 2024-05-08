/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> res;

        // 给定四个遍历的边界，因为遍历的顺序是确定的
        int m = matrix.size(), n = matrix.front().size();
        int up = 0, down = m - 1, left = 0, right = n - 1;

        while (1) {
            // 向右
            for (int j = left; j <= right; ++j)
                res.push_back(matrix[up][j]);
            // 因为结束肯定是在到达边界的时候结束，所以我在这里做判断
            if (m * n == res.size())
                break;
            ++up;
            // 向下
            for (int i = up; i <= down; ++i)
                res.push_back(matrix[i][right]);
            if (m * n == res.size())
                break;
            --right;
            // 向左
            for (int j = right; j >= left; --j)
                res.push_back(matrix[down][j]);
            if (m * n == res.size())
                break;
            --down;
            // 向上
            for (int i = down; i >= up; --i)
                res.push_back(matrix[i][left]);
            if (m * n == res.size())
                break;
            ++left;
        }

        return res;
    }
};
// @lc code=end
