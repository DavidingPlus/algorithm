/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int letterToNum(char ch) {
        if ('A' == ch)
            return 1;
        else if ('C' == ch)
            return 2;
        else if ('G' == ch)
            return 3;
        else if ('T' == ch)
            return 4;
        return 0;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        // 滑动窗口
        vector<string> res;
        unordered_map<int, int> vals;  // 拿一个vals存储哈希值和出现的次数

        if (s.size() < 10)
            return res;

        // 对于碱基的排列，我们做一个数字的映射，这样可以很方便的比较是否重复，将时间复杂度减少为O(1)
        long long num = 0;
        for (int i = 0; i < 10; ++i)
            num = 10 * num + letterToNum(s[i]);
        ++vals[num];

        for (int right = 10; right < s.size(); ++right) {
            num -= letterToNum(s[right - 10]) * 1e9;
            num = 10 * num + letterToNum(s[right]);

            if (vals[num] > 1)
                continue;
            if (1 == vals[num]) {
                res.push_back(s.substr(right - 9, 10));
            }

            ++vals[num];
        }

        return res;
    }
};
// @lc code=end
