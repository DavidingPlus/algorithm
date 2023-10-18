/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e4 + 10;

class Solution {
public:
    // 带有备忘录的自顶而下的递归算法
    // int memo[N] = {0};  // 用来做备忘录

    // int coinChange(vector<int>& coins, int amount) {
    //     // 这个问题可以用递归来解决
    //     // 我们把amount拆分为每个硬币加上硬币减去这个值的子问题
    //     // 然后遍历一遍整个数组得出去一个最小值就得出了答案

    //     if (0 == amount)
    //         return 0;
    //     if (amount < 0)
    //         return -1;

    //     if (0 != memo[amount])
    //         return memo[amount];

    //     // 否则需要找出这个值
    //     int ret = __INT_MAX__;
    //     for (auto& val : coins) {
    //         // 对于找不到的东西，最终他会减为小于0，返回-1
    //         int sub_count = coinChange(coins, amount - val);
    //         if (-1 == sub_count)
    //             continue;
    //         ret = min(ret, sub_count + 1);
    //     }

    //     memo[amount] = (__INT_MAX__ == ret) ? -1 : ret;
    //     return memo[amount];
    // }

    // 我们通过迭代来做这个题
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.resize(amount + 1);
        fill(dp.begin(), dp.end(), __INT_MAX__ - 100);  // 为了防止溢出
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            // 和前面的思路是一样的，分解为子问题
            for (auto& val : coins) {
                if (i - val < 0)
                    continue;  // 无解，跳过
                dp[i] = min(dp[i], 1 + dp[i - val]);
            }
        }
        return (__INT_MAX__ - 100 == dp[amount]) ? -1 : dp[amount];
    }
};
// @lc code=end
