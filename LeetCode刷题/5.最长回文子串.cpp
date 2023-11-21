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
        while (i >= 0 and j < s.size()) {
            if (s[i] != s[j])
                break;
            --i, ++j;
        }
        // 这里的i是跳出循环的下一次，注意转换为上一次的
        return string(s.begin() + i + 1, s.begin() + j);
    }

    string longestPalindrome(string s) {
        // 回文串的个数可能是奇数也可能是偶数
        // 对于s中的每个字符，以自己为中心有一个回文串，以自己和下一个一起为中心也可以构成回文串
        // 我们尝试把这些回文串全部找出来，然后就可以比较大小了

        string res;
        for (int i = 0; i < s.size(); ++i) {
            string s1 = Palindrome(s, i, i);
            string s2;
            if (i != s.size() - 1)
                s2 = Palindrome(s, i, i + 1);

            auto& longer = (s1.size() >= s2.size()) ? s1 : s2;
            res = (res.size() >= longer.size()) ? res : longer;
        }

        return res;
    }
};
// @lc code=end
