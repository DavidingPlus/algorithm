/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

#include <bits/stdc++.h>


class MyQueue
{

public:

    MyQueue() {}

    void push(int x) { m_inputS.push(x); }

    int pop()
    {
        int res = peek();

        m_outputS.pop();

        return res;
    }

    int peek()
    {
        if (m_outputS.empty())
        {
            while (!m_inputS.empty())
            {
                int v = m_inputS.top();
                m_inputS.pop();
                m_outputS.push(v);
            }
        }

        return m_outputS.top();
    }

    bool empty() { return m_inputS.empty() && m_outputS.empty(); }


private:

    // 见图，m_inputS 做输入栈，m_outputS 做输出栈
    // 两个栈的输入和输出有限制，输出的时候只能从 m_outputS 中拿，如果 m_outputS 空了，就一次性把 m_inputS 中的所有元素压到 m_outputS 中，这样顺序就对了
    std::stack<int> m_inputS, m_outputS;
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
