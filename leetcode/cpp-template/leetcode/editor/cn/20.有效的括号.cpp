/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:


    // 这是一个标准的栈的模板题。进入的元素与栈顶相匹配，最后如果都能匹配必然会被清空。自己模拟一下过程即可。

    bool check(char left, char right) { return ('(' == left && ')' == right) || ('{' == left && '}' == right) || ('[' == left && ']' == right); }

    bool isValid(std::string s)
    {
        std::stack<char> st;

        for (auto &ch : s)
        {
            if (!st.empty())
            {
                check(st.top(), ch) ? st.pop() : st.push(ch);
            }
            else
            {
                st.push(ch);
            }
        }


        return st.empty();
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
