/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 升序数组，找到最后一个平方不大于 x 的数
    int mySqrt(int x)
    {
        // 改为除法以后需要注意除数为 0 的问题，经测试需要做一些特判
        if (0 == x) return 0;
        if (1 == x) return 1;

        int left = 0, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 乘法会越界，在乘法的基础上改为除法
            if (x / mid == mid)
            {
                left = mid + 1;
            }
            else if (mid > x / mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return right;
    }
};

// @lc code=end
