/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::string removeDuplicates(std::string s)
    {
        // 这个题目和使用栈处理括号匹配的那个题目没有任何区别，模拟一下过程即可
        // 只不过这里就是用一个字符串模拟栈了，本质是一样的

        std::string res;
        res.reserve(s.size());

        for (auto &c : s)
        {
            if (!res.empty())
            {
                c == res.back() ? res.pop_back() : res.push_back(c);
            }
            else
            {
                res.push_back(c);
            }
        }

        return res;
    }
};

// @lc code=end
