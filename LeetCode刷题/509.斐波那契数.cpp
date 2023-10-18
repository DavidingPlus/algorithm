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
    //     if (0 == n)
    //         return 0;
    //     if (1 == n)
    //         return 1;

    //     return fib(n - 1) + fib(n - 2);
    // }

    // 通过备忘录进行了优化
    // int Fib[N] = {0};

    // int fib(int n) {
    //     if (0 == n)
    //         return 0;
    //     if (1 == n)
    //         return 1;

    //     // 如果备忘录中存在直接用即可
    //     if (0 != Fib[n])
    //         return Fib[n];

    //     Fib[n] = fib(n - 1) + fib(n - 2);
    //     return Fib[n];
    // }

    // 将递归变为迭代，通过线性dp求解
    // int fib(int n) {
    //     int dp[N];  // 这个东西做备忘录

    //     dp[0] = 0, dp[1] = 1;
    //     for (int i = 2; i <= n; ++i)
    //         dp[i] = dp[i - 1] + dp[i - 2];

    //     return dp[n];
    // }

    // 我们可以进一步优化空间复杂度为O(1)
    int fib(int n) {
        if (0 == n || 1 == n)
            return n;

        // 我们只用两个变量就可以记录n-1和n-2的数组值
        int dp_i_2 = 0, dp_i_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = dp_i_2;

            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i_1 + tmp;
        }
        return dp_i_1;
    }
};
// @lc code=end
