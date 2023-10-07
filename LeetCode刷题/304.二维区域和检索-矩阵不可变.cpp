/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 210;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // 前缀和数组从1开始，可以不用考虑边界条件
        for (int i = 1; i <= matrix.size(); ++i)
            for (int j = 1; j <= matrix[0].size(); ++j) {
                nums[i][j] = matrix[i - 1][j - 1];
                presums[i][j] = presums[i - 1][j] + presums[i][j - 1] - presums[i - 1][j - 1] + nums[i][j];
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return presums[row2 + 1][col2 + 1] - presums[row2 + 1][col1] - presums[row1][col2 + 1] + presums[row1][col1];
    }

private:
    int nums[N][N] = {0};  // 定义数值数组

    int presums[N][N] = {0};  // 定义二维前缀和数组
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
