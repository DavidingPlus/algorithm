/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <stdio.h>

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    int a = 0, b = 1;

    for (int i = 2; i <= 1 + n; ++i)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return a;
}
// @lc code=end
