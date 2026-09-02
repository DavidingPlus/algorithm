/*
 * @lc app=leetcode.cn id=304 lang=cpp
 * @lcpr version=30404
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

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

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end


int main()
{
}


/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */
