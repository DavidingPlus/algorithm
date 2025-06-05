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
        // 这里出来的i和j是分别再往外扩了一步，真正满足条件的位置是i+1到j-1
        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        // 回文串的个数可能是奇数也可能是偶数
        // 对于s中的每个字符，自己单个字符当然是回文串，由于是找到最长回文子串，以自己为中心有一个最长回文串，以自己和下一个一起为中心也可以构成最长回文串（当然这个要这俩满足才行）
        // 我们尝试把这些最长回文串全部找出来，然后就可以比较大小了

        auto res = string();

        for (int i = 0; i < s.size(); ++i) {
            string one = Palindrome(s, i, i), two;

            if (!(s.size() - 1 == i || s[i] != s[i + 1]))
                two = Palindrome(s, i, i + 1);

            auto &longer = one.size() >= two.size() ? one : two;

            res = res.size() >= longer.size() ? res : longer;
        }
        return res;
    }
};
// @lc code=end
