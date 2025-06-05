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
    // Solution() {
    //     memo.resize(N);
    //     fill(memo.begin(), memo.end(), -666);
    // }

    // vector<int> memo;  // 用来做备忘录，记录面额n需要的最小硬币个数

    // int coinChange(vector<int>& coins, int amount) {
    //     // 这个问题可以用递归来解决
    //     // 我们把amount拆分为每个硬币加上硬币减去这个值的子问题
    //     // 然后遍历一遍整个数组得出去一个最小值就得出了答案
    //     if (0 == amount)
    //         return 0;
    //     if (amount < 0)
    //         return -1;

    //     // 这两个的顺序是没有影响的，但是为了防止amount为负数导致越界放在下面
    //     if (-666 != memo[amount])  // 这里包含了两种情况，都是已经有结果的，就是嫩巩固凑出的最小的个数以及凑不出，就是-1
    //         return memo[amount];

    //     // 遍历每个硬币
    //     int res = __INT_MAX__;
    //     for (auto& coin : coins) {
    //         int count = coinChange(coins, amount - coin);
    //         if (-1 == count)
    //             continue;
    //         res = min(res, 1 + count);
    //     }
    //     // 更新memo数组
    //     memo[amount] = (__INT_MAX__ != res) ? res : -1;
    //     return memo[amount];
    // }

    // 我们通过迭代来做这个题
    int coinChange(vector<int>& coins, int amount) {
        // dp数组的含义是面额n需要的最小硬币个数
        vector<int> dp(N);
        fill(dp.begin(), dp.end(), __INT_MAX__ - 666);  //-666是为了防止+1然后越界

        // 我们需要通过n来推出n + 1
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            // 后面的思路和递归是一样的，遍历分成子问题然后去最小值，迭代的过程中下标小的一定已经计算出来了，所以直接用即可
            for (auto& coin : coins) {
                // i - coin可能为负数，这是不允许的
                // 跳过的第二种情况就是已经直到这个面值找不到了，就是-1
                if (i - coin < 0 || -1 == dp[i - coin])
                    continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
            if (__INT_MAX__ - 666 == dp[i])
                dp[i] = -1;
        }
        return dp[amount];
    }
};
// @lc code=end
