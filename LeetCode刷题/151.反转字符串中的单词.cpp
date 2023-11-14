/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    void reverse_range(string& s, int left, int right) {
        while (left <= right) {
            char ch = s[left];
            s[left] = s[right];
            s[right] = ch;

            ++left;
            --right;
        }
    }

    string reverseWords(string s) {
        // 先去掉多余的空格
        string res;
        for (auto& ch : s) {
            // 先不考虑头尾，有空格只保留一个
            if (!res.empty() and ' ' == ch and ' ' == res.back())
                continue;

            res += ch;
        }
        // 去除头尾
        if (' ' == res.front())
            res.erase(res.begin());
        if (' ' == res.back())
            res.pop_back();

        // 然后的思路是，先对整个字符串进行反转，然后找到每个字符串分别进行反转...
        reverse_range(res, 0, res.size() - 1);

        int left = 0;
        for (int i = 0; i < res.size(); ++i)
            if (' ' == res[i]) {
                reverse_range(res, left, i - 1);
                left = i + 1;
            }

        // 对最后一个单词做翻转
        reverse_range(res, left, res.size() - 1);

        return res;
    }
};
// @lc code=end
