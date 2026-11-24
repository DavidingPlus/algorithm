/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30404
 *
 * [63] 不同路径 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    // 思路完全同 62 题，只是多了一个障碍物的判断。
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        std::vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i)
        {
            std::vector<int> tmp(n, 0);

            for (int j = 0; j < n; ++j)
            {
                // 如果当前位置是障碍物，直接返回。
                if (obstacleGrid[i][j]) continue;
                // 判断上方位置。由于我们构造了一个虚拟第 0 行，所以 0 == i 时，这个分支也应该走到。
                if (!i || !obstacleGrid[i - 1][j]) tmp[j] += dp[j];
                // 判断左方位置。
                if (j && !obstacleGrid[i][j - 1]) tmp[j] += tmp[j - 1];
            }

            std::swap(dp, tmp);
        }


        return dp[n - 1];
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[0,1]]\n
// @lcpr case=end

 */
