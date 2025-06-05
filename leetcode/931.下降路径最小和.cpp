/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 100 + 10;

class Solution {
public:
    // 迭代的思路，与之类似的还有递归带有备忘录的解法，这里就不写了
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 由于向下的时候只能左右最多偏差一次，所以最后一行的任意一列都可能成为答案，因此我们只能老老实实的记录
        vector<vector<int>> dp;
        dp.resize(1 + n);
        dp[0].resize(n);
        // dp[0]做边界的初始化
        fill(dp[0].begin(), dp[0].end(), 0);

        int res = __INT_MAX__;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i].push_back(matrix[i - 1][j] +
                                min(dp[i - 1][j],
                                    min((j - 1 >= 0) ? dp[i - 1][j - 1] : __INT_MAX__, (j + 1 < n) ? dp[i - 1][j + 1] : __INT_MAX__)));

                if (n == i)
                    res = min(res, dp[i].back());
            }
        }

        return res;
    }
};
// @lc code=end
