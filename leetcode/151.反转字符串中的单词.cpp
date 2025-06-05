/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::string reverseWords(std::string s)
    {
        // 先切片再合并
        // 切片利用状态机的思路，当遇到第一个非空的字符，进入字符状态，存储另一个指针往有遍历，知道遇到空字符或者越界结束。空字符就进入下一个循环，越界就计算结束。

        std::vector<std::string> words;

        int i = 0;
        while (1)
        {
            if (' ' != s[i])
            {
                int j = i;
                for (; ' ' != s[j] && j < s.size(); ++j)
                    ;

                words.push_back(s.substr(i, j - i));

                // 最后一个单词也要写入数组，因此跳出放在后面
                if (j == s.size()) break;

                i = j;
            }
            else
            {
                ++i;

                if (i == s.size()) break;
            }
        }

        std::string res;
        for (int i = words.size() - 1; i >= 0; --i)
        {
            res += words[i];

            if (i) res += ' ';
        }


        return res;
    }

    // TODO 如何在原地修改的情况下，即空间复杂度为 O(1) 下完成本题？
    // std::string reverseWords(std::string s)
    // {
    // }
};

// @lc code=end
