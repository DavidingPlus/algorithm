/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        s.push({val,
                s.empty() ? val : min(s.top().second, val)});
    }

    void pop() { s.pop(); }

    int top() { return s.top().first; }

    int getMin() { return s.top().second; }

private:
    // 由于下层的最小值与上层无关，因为需要访问下层的最小值的时候上层早就弹出了，因此对于每一层可以维护一个最小值，这样插入的时候就能够很方便的判断了
    // 为了节省空间，我就拿pair存了
    stack<pair<int, int>> s;
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
