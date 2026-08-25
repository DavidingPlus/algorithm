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
        // 一样的使用栈的思想

        // 操作符是不会被压入栈的，因此类型使用 int 即可
        std::stack<int> ss;

        for (auto &s : tokens)
        {
            if (!ss.empty())
            {
                if (check(s))
                {
                    // 开始计算
                    int right = ss.top();
                    ss.pop();

                    int left = ss.top();
                    ss.pop();

                    int res = calc(left, right, s);
                    ss.push(res);
                }
                else
                {
                    ss.push(std::stoi(s));
                }
            }
            else
            {
                ss.push(std::stoi(s));
            }
        }

        return ss.top();
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
