/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> findAnagrams(string s1, string s2) {
        // 这个题和字符串排列那个题没区别啊...
        vector<int> res;

        if (s2.size() > s1.size())
            return res;

        unordered_map<char, int> um1;
        for (auto& ch : s2)
            ++um1[ch];

        unordered_map<char, int> um2;
        int left = 0, right = 0;

        while (right - left < s2.size()) {
            ++um2[s1[right]];
            ++right;
        }

        if (um1 == um2)
            res.push_back(left);

        while (right < s1.size()) {
            // 左边弹出
            if (1 == um2[s1[left]])
                um2.erase(s1[left]);
            else
                --um2[s1[left]];
            ++left;

            // 右边进入
            ++um2[s1[right]];
            ++right;

            if (um1 == um2)
                res.push_back(left);
        }

        return res;
    }
};
// @lc code=end
