/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 参考 69 题写一个二分判断即可：https://leetcode.cn/problems/sqrtx/
    bool isPerfectSquare(int num)
    {
        // if (0 == num) return true;
        if (1 == num) return true;

        int left = 0, right = num;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (num / mid == mid)
            {
                left = mid + 1;
            }
            else if (mid > num / mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return num == right * right ? true : false;
    }
};
// @lc code=end
