/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start


class Solution
{

public:

    // 本题思路完全同 279 题。

    // 解法 1：迭代。
    int coinChange(std::vector<int> &coins, int amount)
    {
        // dp 数组的含义是面额 n 需要的最小硬币个数。
        // XXX 不管 coins 如何设计，题目可能的最大值就是 amount（全用 1 去凑），为了防止 1 + dp[i - coin] 越界（原来初始化为 std::numeric_limits<int>::max()），可以用 1 + amount 来初始化。
        std::vector<int> dp(1 + amount, 1 + amount);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (auto &coin : coins)
            {
                // 与 279 题不同的是，本题需要考虑 dp[i - coin] 不存在的情况，因为 coins 可能无法兑换出 amount 的零钱。不像完全平方数，至少有一组解，n * 1 * 1。
                if (coin <= i) dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }


        return 1 + amount == dp[amount] ? -1 : dp[amount];
    }


    // XXX 解法 2：递归。本题不推荐，开销太大，但可以熟悉语法。
    // int coinChange(std::vector<int> &coins, int amount)
    // {
    //     int INF = 1 + amount;

    //     // -1 代表尚未计算。不为 -1 代表已经被计算过了，可能是有解的值或者无解的 INF。
    //     std::vector<int> memo(1 + amount, -1);
    //     memo[0] = 0;

    //     // 递归函数的知识见 0.递归函数.md。
    //     auto impl = [&](auto &&self, int remain)
    //     {
    //         // 包含了 if(0 == remain) return 0; 的特判。
    //         if (-1 != memo[remain]) return memo[remain];

    //         int res = INF;

    //         for (auto &coin : coins)
    //         {
    //             if (coin <= remain) res = std::min(res, 1 + self(self, remain - coin));
    //         }

    //         memo[remain] = res;


    //         return res;
    //     };

    //     int res = impl(impl, amount);


    //     return INF == res ? -1 : res;
    // }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
