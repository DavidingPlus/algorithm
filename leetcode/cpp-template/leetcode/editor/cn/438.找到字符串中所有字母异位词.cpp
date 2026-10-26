/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

class Solution
{

public:

    // 这题和 567 题没有任何区别，具体思路见 567 题。
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        std::vector<int> res;
        std::unordered_map<char, int> ump, ums;

        for (auto &ch : p) ++ump[ch];

        int left = 0, right = 0, valid = 0;
        while (right < s.size())
        {
            char ch = s[right++];
            if (ump.count(ch))
            {
                if (ump[ch] == ums[ch]) --valid;

                ++ums[ch];

                if (ump[ch] == ums[ch]) ++valid;
            }

            if (p.size() == right - left)
            {
                if (ump.size() == valid) res.emplace_back(left);

                ch = s[left++];
                if (ump.count(ch))
                {
                    if (ump[ch] == ums[ch]) --valid;

                    --ums[ch];

                    if (ump[ch] == ums[ch]) ++valid;
                }
            }
        }


        return res;
    }


    // 旧版代码。
    // std::vector<int> findAnagrams(std::string s, std::string p)
    // {
    //     if (s.length() < p.length()) return {};

    //     std::array<int, 26> hashP;
    //     std::fill(hashP.begin(), hashP.end(), 0);

    //     for (auto &c : p) ++hashP[c - 'a'];

    //     std::array<int, 26> hashS;
    //     std::fill(hashS.begin(), hashS.end(), 0);

    //     for (int i = 0; i < p.length(); ++i) ++hashS[s[i] - 'a'];

    //     std::vector<int> res;

    //     // 利用滑动窗口扫即可
    //     for (int i = 0; i + p.length() - 1 < s.length(); ++i)
    //     {
    //         if (hashS == hashP) res.emplace_back(i);

    //         --hashS[s[i] - 'a'];

    //         // 位于数组末尾不用插入下一个，做一个特判
    //         if (i + p.length() < s.length()) ++hashS[s[i + p.length()] - 'a'];
    //     }

    //     return res;
    // }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
