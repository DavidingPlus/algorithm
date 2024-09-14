/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    void reverse(std::string &s, int left, int right)
    {
        for (; left <= right; ++left, --right) std::swap(s[left], s[right]);
    }

    std::string reverseStr(std::string s, int k)
    {
        // 以 2k 的位置对整个字符串分段
        int count = s.size() / (2 * k);

        // 处理正常翻转的字符串
        for (int i = 0; i < count; ++i) reverse(s, i * (2 * k), (i + 1) * (2 * k) - 1 - k);

        // 处理剩余部分
        int remain = s.size() - count * (2 * k);

        if (remain < k) reverse(s, count * (2 * k), s.size() - 1);
        if (remain >= k && remain < 2 * k) reverse(s, count * (2 * k), count * (2 * k) + k - 1);

        return s;
    }
};
// @lc code=end
