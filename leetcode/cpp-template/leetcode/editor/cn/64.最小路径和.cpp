/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

class Solution
{

public:

    // 思路依旧同 62 题。
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // 依旧虚拟第 0 行，这一行除了第一个元素是 0 以外，其他的值都是无穷大，代表无法从这里得到最小路径。第一个元素为 0 代表从这里开始，是为了保证第一行的第一个元素被正确迭代。
        std::vector<int> dp(n, std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 0; i < m; ++i)
        {
            std::vector<int> tmp(n, 0);

            for (int j = 0; j < n; ++j)
            {
                tmp[j] = dp[j];

                if (j) tmp[j] = std::min(tmp[j], tmp[j - 1]);

                tmp[j] += grid[i][j];
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
