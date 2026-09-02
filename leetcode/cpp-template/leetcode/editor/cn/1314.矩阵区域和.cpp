/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class NumMatrix
{

public:

    NumMatrix(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();

        preSum.resize(1 + m, std::vector<int>(1 + n, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j) preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return preSum[1 + row2][1 + col2] - preSum[row1][1 + col2] - preSum[1 + row2][col1] + preSum[row1][col1];
    }

    std::vector<std::vector<int>> preSum;
};


class Solution
{

public:

    // 前缀和的板子直接用 304 题的即可。
    std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>> &mat, int k)
    {

        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));

        NumMatrix numMatrix(mat);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int x1 = std::max(i - k, 0),
                    y1 = std::max(j - k, 0),
                    x2 = std::min(i + k, m - 1),
                    y2 = std::min(j + k, n - 1);

                res[i][j] = numMatrix.sumRegion(x1, y1, x2, y2);
            }
        }


        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
