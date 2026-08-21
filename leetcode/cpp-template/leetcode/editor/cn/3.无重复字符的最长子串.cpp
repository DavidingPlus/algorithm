/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>

const int N = 5 * 1e4 + 10;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        // 滑动窗口在动态规划中的应用
        // dp[i]代表以i字符结尾的最长不重复子串
        int res = 1, dp[N] = {0};
        dp[0] = 1;

        for (int i = 1; i < s.size(); ++i) {
            // 上一个子串肯定是不重复的，所以find和rfind没区别
            size_t pos = string(s.begin() + i - dp[i - 1], s.begin() + i).find(s[i]);

            // 如果找不到直接更新
            if (string::npos == pos)
                dp[i] = 1 + dp[i - 1];
            else
                dp[i] = i - (pos + i - dp[i - 1]);

            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end
