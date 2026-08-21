/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=20003
 *
 * [518] 零钱兑换 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int change(int amount, std::vector<int> &coins)
    {
        int m = coins.size(), n = amount;

        // 使用滚动数组优化空间复杂度，逻辑请从二维考虑。
        std::vector<int> dp(1 + n);
        // 初始条件，不用任何硬币凑出 0 面额有 1 种方法。考虑 [1] 凑出 1 的过程，即可反推出此条件。
        dp[0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (j >= coins[i]) dp[j] += dp[j - coins[i]];
            }
        }


        return dp[n];
    }
};

// @lc code=end


/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
