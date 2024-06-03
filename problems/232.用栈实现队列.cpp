/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>

class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }

    int peek() {
        if (empty())
            return -1;

        if (!s2.empty())
            return s2.top();
        // 把s1的所有压进s2
        while (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    // 见图，s1做输入栈，s2做输出栈
    // 两个栈的输入和输出有限制，输出的时候只能从s2中拿，如果s2空了，就一次性把s1中的所有元素压到s2中，这样顺序就对了
    stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated && called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
