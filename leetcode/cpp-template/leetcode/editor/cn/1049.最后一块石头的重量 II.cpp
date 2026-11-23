/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 * @lcpr version=30404
 *
 * [1049] 最后一块石头的重量 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int lastStoneWeightII(std::vector<int> &stones)
    {
        // XXX 任意两个石头会互相抵消，问你最后留下的石头重量，相当于是把 stones 数组分成两个子集，使得两个子集的重量差最小。想要两个子集的重量差最小，那么两个子集的重量和应该尽可能接近 sum / 2。

        int sum = std::accumulate(stones.begin(), stones.end(), 0),
            m = stones.size(),
            n = sum / 2;

        std::vector<std::vector<int>> dp(1 + m, std::vector<int>(1 + n, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j];

                if (j - stones[i - 1] >= 0) dp[i][j] = std::max(dp[i][j], stones[i - 1] + dp[i - 1][j - stones[i - 1]]);
            }
        }


        return sum - 2 * dp[m][n];
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
// [2,7,4,1,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [31,26,33,21,40]\n
// @lcpr case=end

 */
