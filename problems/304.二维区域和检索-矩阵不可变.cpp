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
    int preSum[N][N] = {{0}};

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // 同一维的思路，只是复杂了一些
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix.front().size(); ++j)
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated && called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
