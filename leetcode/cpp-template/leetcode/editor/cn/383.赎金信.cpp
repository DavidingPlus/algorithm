/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        // 同 242 题的思路，ransomNote 做减法，magazine 做加法，如果最后剩下的结果每个值都是 >=0 的就满足

        int hash[26] = {0};

        for (auto &c : ransomNote) --hash[c - 'a'];
        for (auto &c : magazine) ++hash[c - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            if (hash[i] < 0) return false;
        }

        return true;
    }
};

// @lc code=end
