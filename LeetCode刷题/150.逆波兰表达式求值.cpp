/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
    bool isDigit(const string& ch) {
        return !(("+" == ch) or
                 ("-" == ch) or
                 ("*" == ch) or
                 ("/" == ch));
    }

    int calculate(const int& num1, const int& num2, const string& op) {
        if ("+" == op)
            return num1 + num2;
        else if ("-" == op)
            return num1 - num2;
        else if ("*" == op)
            return num1 * num2;
        else if ("/" == op)
            return num1 / num2;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;

        // 画图模拟一下求值的过程，每次都取出最后进来的两个，所以也是栈
        // 题目给出的式子是一定有含义的
        stack<int> s;
        int res = atoi(tokens[0].c_str());  // 为防止就一个数，赋值给初始值的数字
        for (auto& str : tokens) {
            if (isDigit(str))
                s.push(atoi(str.c_str()));
            else {
                // 弹出计算值在入栈
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                res = calculate(num1, num2, str);
                s.push(res);
            }
        }
        return res;
    }
};
// @lc code=end
