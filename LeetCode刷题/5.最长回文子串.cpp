/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // 这个函数用来在下标i和j往外扩张的最大回文串，当然前提是i和j之间符合回文串特征
    string Palindrome(string s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }

        return string(s.begin() + i + 1, s.begin() + j);
    }

    string longestPalindrome(string s) {
        // 回文串的个数可能是奇数也可能是偶数
        // 对于s中的每个字符，以自己为中心有一个回文串，以自己和下一个一起为中心也可以构成回文串
        // 我们尝试把这些回文串全部找出来，然后就可以比较大小了
        string ret;

        for (int i = 0; i < s.size(); ++i) {
            // 以本字符为中心的奇数个数的最大回文串
            string s1 = Palindrome(s, i, i);
            // 以本字符和下一个字符为中心的奇数个数的最大回文串
            string s2;
            if (i != s.size() - 1)
                s2 = Palindrome(s, i, i + 1);

            string longer = (s1.size() >= s2.size()) ? s1 : s2;

            ret = (longer.size() > ret.size()) ? longer : ret;
        }

        return ret;
    }
};
// @lc code=end
