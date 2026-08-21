/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::vector<int> findAnagrams(std::string s1, std::string s2)
    {
        if (s1.length() < s2.length()) return {};

        std::array<int, 26> hashP;
        std::fill(hashP.begin(), hashP.end(), 0);

        for (auto &c : s2) ++hashP[c - 'a'];

        std::array<int, 26> hashS;
        std::fill(hashS.begin(), hashS.end(), 0);

        for (int i = 0; i < s2.length(); ++i) ++hashS[s1[i] - 'a'];

        std::vector<int> res;

        // 利用滑动窗口扫即可
        for (int i = 0; i + s2.length() - 1 < s1.length(); ++i)
        {
            if (hashS == hashP) res.emplace_back(i);

            --hashS[s1[i] - 'a'];

            // 位于数组末尾不用插入下一个，做一个特判
            if (i + s2.length() < s1.length()) ++hashS[s1[i + s2.length()] - 'a'];
        }

        return res;
    }
};

// @lc code=end
