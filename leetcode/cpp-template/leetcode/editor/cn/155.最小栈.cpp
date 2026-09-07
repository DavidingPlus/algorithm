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

    void push(int val) { st.push({val, st.empty() ? val : std::min(val, getMin())}); }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }


private:

    // 由于下层的最小值与上层无关，因为需要访问下层的最小值的时候上层早就弹出了，因此对于每一层可以维护一个最小值，这样插入的时候就能够很方便的判断了。为了节省空间，就拿 std::pair 存了。
    std::stack<std::pair<int, int>> st;
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
