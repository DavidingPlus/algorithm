/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    // 一样的使用栈的思想。

    bool check(const std::string &s) { return ("+" == s) || ("-" == s) || ("*" == s) || ("/" == s); }

    int calc(int left, int right, const std::string &op)
    {
        if ("+" == op)
        {
            return left + right;
        }
        else if ("-" == op)
        {
            return left - right;
        }
        else if ("*" == op)
        {
            return left * right;
        }
        else
        {
            return left / right;
        }
    }

    int evalRPN(std::vector<std::string> &tokens)
    {
        // 操作符是不会被压入栈的，因此类型使用 int 即可
        std::stack<int> st;

        for (auto &s : tokens)
        {
            if (!st.empty())
            {
                if (check(s))
                {
                    int right = st.top();
                    st.pop();

                    int left = st.top();
                    st.pop();

                    st.push(calc(left, right, s));
                }
                else
                {
                    st.push(std::stoi(s));
                }
            }
            else
            {
                st.push(std::stoi(s));
            }
        }


        return st.top();
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
