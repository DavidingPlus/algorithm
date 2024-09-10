/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int squareSum(int n)
    {
        int res = 0;

        for (; n; n = n / 10) res += (n % 10) * (n % 10);

        return res;
    }

    bool isHappy(int n)
    {
        // 数学证明参考：https://leetcode.cn/problems/happy-number/solutions/225976/kuai-le-de-zhi-shi-dian-zeng-jia-liao-by-sweetiee/
        // 结论是：当无限循环的时候，一定是走到了环的位置，也就是不会存在一个一直走下去的序列，这就是经典的链表环的快慢指针问题

        int fast = n, slow = n;
        while (1) // 循环跳出条件不写在 while 循环上是为了防止在初始条件的时候就跳出循环
        {
            fast = squareSum(squareSum(fast));
            slow = squareSum(slow);

            if (fast == slow) break;
        }

        // 循环跳出的条件只有两种情况，一种是遇到环，不是快乐数；一种是 fast 和 slow 最后都变成 1
        return 1 == fast;
    }
};

// @lc code=end
