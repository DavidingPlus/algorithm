/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 200 + 10;

class NumMatrix {
private:
    int preSum[N][N] = {0};  // 定义二维前缀和数组

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // 前缀和数组从1开始，可以不用考虑边界条件
        for (int i = 1; i <= matrix.size(); ++i)
            for (int j = 1; j <= matrix[0].size(); ++j)
                preSum[i][j] = matrix[i - 1][j - 1] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
