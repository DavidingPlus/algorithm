/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30404
 *
 * [474] 一和零
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int findMaxForm(std::vector<std::string> &strs, int m, int n)
    {
        // 每个元素取或不取，这看起来就是一个 01 背包问题，但是和传统 01 背包问题不同的是，本题目有两个限制条件，而传统 01 背包只要求整体容量不超过 V 即可。这里要求子集最多有 m 个 0 和 n 个 1。怎么办？增加维度即可。

        // dp[i][j][k] 表示只考虑前 i 个字符串，在最多使用 j 个 0 和 k 个 1 的限制下，能组成的最大子集长度。
        std::vector<std::vector<std::vector<int>>> dp(1 + strs.size(),
                                                      std::vector<std::vector<int>>(1 + m,
                                                                                    std::vector<int>(1 + n, 0)));

        for (int i = 1; i <= strs.size(); ++i)
        {
            // 遍历字符串得到 0 和 1 的个数。
            int zeroCount = 0, oneCount = 0;
            // 题目保证 strs[i - 1] 仅由 '0' 和 '1' 组成。
            for (auto &ch : strs[i - 1]) '0' == ch ? ++zeroCount : ++oneCount;

            for (int j = 0; j <= m; ++j)
            {
                for (int k = 0; k <= n; ++k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];

                    if (j - zeroCount >= 0 && k - oneCount >= 0) dp[i][j][k] = std::max(dp[i][j][k], 1 + dp[i - 1][j - zeroCount][k - oneCount]);
                }
            }
        }


        return dp[strs.size()][m][n];
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
// ["10","0001","111001","1","0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10","0","1"]\n1\n1\n
// @lcpr case=end

 */
