/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start

#include <bits/stdc++.h>


class MyStack
{

public:

    MyStack() {}

    void push(int x) { m_q.push(x); }

    int pop()
    {
        int count = m_q.size();
        for (int i = 0; i < count - 1; ++i)
        {
            int v = m_q.front();
            m_q.pop();
            m_q.push(v);
        }

        int res = m_q.front();
        m_q.pop();

        return res;
    }

    int top()
    {
        int res = pop();
        m_q.push(res);

        return res;
    }

    bool empty() { return m_q.empty(); }


private:

    // 只需要一个队列就够了
    // 思路就是每次pop的时候都把前面的元素出队列然后放到末尾去，这样最后进来的就在队头了，并且其他的顺序不变，下次重复相同的操作即可
    std::queue<int> m_q;
};

/**
 * Your MyStack object will be instantiated && called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
