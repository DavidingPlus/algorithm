/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start


class MinStack
{

public:

    MinStack() {}

    void push(int value) { m_st.emplace(value, m_st.empty() ? value : std::min(m_st.top().second, value)); }

    void pop() { m_st.pop(); }

    int top() const { return m_st.top().first; }

    int getMin() const { return m_st.top().second; }

    // 本来是可以直接拿优先性队列写的，但是还是用传统栈写吧。
    // XXX 考虑压入某个栈的情况，假设没压入时最小值是 a，新进来可能会产生一个新最小值，但当新进来的数被弹出去以后，最小值依然是 a，换句话说，新进来的元素不会影响已经压入元素的最小值。因此完全可以在维护原来栈的同时，维护一个当前状态的最小值。
    std::stack<std::pair<int, int>> m_st;
};

/**
 * Your MinStack object will be instantiated && called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


int main()
{
}
