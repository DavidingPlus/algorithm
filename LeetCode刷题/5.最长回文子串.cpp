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
        while (i >= 0 and j < s.size() and s[i] == s[j]) {
            --i;
            ++j;
        }

        // 这里的i和j是下一次不满足条件的下标，记得做处理
        return string(s.begin() + i + 1, s.begin() + j);
    }

    string longestPalindrome(string s) {
        // 回文串的个数可能是奇数也可能是偶数
        // 对于s中的每个字符，以自己为中心有一个回文串，以自己和下一个一起为中心也可以构成回文串
        // 我们尝试把这些回文串全部找出来，然后就可以比较大小了
        string ret;

        for (int i = 0; i < s.size(); ++i) {
            // 以该字符串为中心的回文串
            string s1 = Palindrome(s, i, i);
            // 以本字符和下一个字符为中心的回文串
            string s2;
            if (i != s.size() - 1 and s[i] == s[i + 1])
                s2 = Palindrome(s, i, i + 1);

            string& longer = (s1.size() >= s2.size()) ? s1 : s2;

            ret = (ret.size() >= longer.size()) ? ret : longer;
        }

        return ret;
    }
};
// @lc code=end
