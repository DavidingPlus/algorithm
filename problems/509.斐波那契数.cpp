/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <cstring>

const int N = 30 + 10;

class Solution {
public:
    // 暴力做法：直接递归
    // 时间复杂度高的一个大问题：重复子问题的计算
    // 比如fib(19)+fib(18)：19又要拆分为18和17，18就计算了两次，而且还不止一个问题这么干了
    // int fib(int n) {
    //     if (0 == n || 1 == n)
    //         return n;
    //     return fib(n - 1) + fib(n - 2);
    // }

    // 通过备忘录进行了优化
    // int memo[N] = {0};

    // int fib(int n) {
    //     // 先查备忘录
    //     if (0 != memo[n])
    //         return memo[n];

    //     if (0 == n || 1 == n)
    //         return n;
    //     memo[n] = fib(n - 1) + fib(n - 2);
    //     return memo[n];
    // }

    // 将递归变为迭代，通过线性dp求解
    // int fib(int n) {
    //     if (0 == n || 1 == n)
    //         return n;

    //     int dp[N] = {0};
    //     dp[1] = 1;

    //     for (int i = 2; i <= n; ++i)
    //         dp[i] = dp[i - 1] + dp[i - 2];

    //     return dp[n];
    // }

    // 我们可以进一步优化空间复杂度为O(1)
    int fib(int n) {
        if (0 == n || 1 == n)
            return n;

        // 我们用两个变量就能记录，不用开dp[]数组
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = b;
            b += a;
            a = c;
        }
        return b;
    }
};
// @lc code=end
