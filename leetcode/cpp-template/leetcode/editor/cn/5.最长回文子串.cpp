/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{
public:

    // 用来在下标 i 和 j 往外扩张的最大回文串，我们保证 i 和 j 之间的串符合回文串特征。
    std::string palindrome(std::string s, int i, int j)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j]) --i, ++j;
        // 这里出来的 i 和 j 是分别再往外扩了一步，真正满足条件的位置是 i + 1 到 j - 1。
        return s.substr(1 + i, (j - 1) - (1 + i) + 1);
    }

    std::string longestPalindrome(std::string s)
    {
        // 回文串的长度可能是奇数也可能是偶数。
        // 对于 s 中的每个字符，单个字符当然是回文串，由于是找到最长回文子串，以自己为中心有一个最长回文串，以自己和下一个一起为中心也可以构成最长回文串（当然这个要这俩满足才行）。这是 s 中所有可能的回文子串的构成方式。
        // 我们尝试把这些最长回文串全部找出来，然后就可以比较大小了。

        std::string res;

        for (int i = 0; i < s.size(); ++i)
        {
            std::string oddStr = palindrome(s, i, i);

            std::string evenStr;
            if (i != s.size() - 1 && s[i] == s[1 + i]) evenStr = palindrome(s, i, 1 + i);

            auto &longerStr = oddStr.size() > evenStr.size() ? oddStr : evenStr;

            if (res.size() < longerStr.size()) res = longerStr;
        }


        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
