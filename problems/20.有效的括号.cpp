/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    bool check(char right, char left) { return (')' == right && '(' == left) || ('}' == right && '{' == left) || (']' == right && '[' == left); }

    bool isValid(std::string s)
    {
        // 这是一个标准的栈的模板题。进入的元素与栈顶相匹配，最后如果都能匹配必然会被清空。自己模拟一下过程即可

        std::stack<char> sc;

        for (auto &c : s)
        {
            if (!sc.empty())
            {
                check(c, sc.top()) ? sc.pop() : sc.push(c);
            }
            else
            {
                sc.push(c);
            }
        }

        return sc.empty();
    }
};

// @lc code=end
