/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start

#include <bits/stdc++.h>


const int N = 30 + 10;


class Solution
{
public:

    // 解法 1：直接暴力递归
    // 时间复杂度高的一个大问题：重复子问题的计算
    // 比如 fib(19) + fib(18) ：19 又要拆分为 18 和 17，18 就计算了两次，而且还不止一个问题这么干了，时间复杂度是 2^n 次方
    // int fib(int n)
    // {
    //     if (0 == n || 1 == n) return n;

    //     return fib(n - 1) + fib(n - 2);
    // }


    // 解法 2：通过备忘录 memo 优化
    // int memo[N] = {0};

    // int fib(int n)
    // {
    //     if (memo[n]) return memo[n];

    //     if (0 == n || 1 == n)
    //     {
    //         memo[n] = n;
    //     }
    //     else
    //     {
    //         memo[n] = fib(n - 1) + fib(n - 2);
    //     }

    //     return memo[n];
    // }

    // 解法 3：将递归变为迭代，通过线性 dp 求解
    // int fib(int n)
    // {
    //     if (0 == n || 1 == n) return n;

    //     int dp[N] = {0};
    //     dp[1] = 1;

    //     for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];

    //     return dp[n];
    // }

    // 可以进一步优化空间复杂度为 O(1)
    int fib(int n)
    {
        if (0 == n || 1 == n) return n;

        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i)
        {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

// @lc code=end
