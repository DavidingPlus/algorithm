/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::string convert(const std::string &s)
    {
        std::string res;

        for (auto &c : s)
        {
            if ('#' != c) res.push_back(c);
            if ('#' == c && !res.empty()) res.pop_back();
        }

        return res;
    }

    bool backspaceCompare(std::string s, std::string t)
    {
        return convert(s) == convert(t);
    }
};
// @lc code=end
