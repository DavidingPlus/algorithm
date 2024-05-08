/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 100 + 10;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // 先初始化数组和二维前缀和数组
        for (int i = 1; i <= mat.size(); ++i)
            for (int j = 1; j <= mat[0].size(); ++j) {
                nums[i][j] = mat[i - 1][j - 1];
                presums[i][j] = presums[i - 1][j] + presums[i][j - 1] - presums[i - 1][j - 1] + nums[i][j];
            }

        // 开始构造answer矩阵
        vector<vector<int>> answer;
        // TODO

        return answer;
    }

private:
    int nums[N][N] = {0};

    int presums[N][N] = {0};
};
// @lc code=end
