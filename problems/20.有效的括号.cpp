/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>
#include <string>

class Solution {
public:
    bool check(const stack<char>& sc, const char& ch) {
        if ((')' == ch && '(' == sc.top()) or
            (']' == ch && '[' == sc.top()) or
            ('}' == ch && '{' == sc.top()))
            return true;
        return false;
    }

    bool isValid(string s) {
        // 我的左括号在层层消除之后最后必然一个都不剩
        // 以([{}])为例子，设想一个数据结构，存入([{，当我}进来的时候消除}，显然这是一个栈
        stack<char> sc;
        for (auto& ch : s) {
            if (false == sc.empty() && check(sc, ch))
                sc.pop();
            else
                sc.push(ch);
        }
        return sc.empty();
    }
};
// @lc code=end
