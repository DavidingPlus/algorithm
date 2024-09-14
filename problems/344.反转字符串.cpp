/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    void reverseString(std::vector<char> &s)
    {
        // 双指针
        for (int left = 0, right = s.size() - 1; left <= right; ++left, --right) std::swap(s[left], s[right]);
    }
};

// @lc code=end
