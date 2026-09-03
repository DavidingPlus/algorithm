/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class MyStack
{

public:

    MyStack() {}

    void push(int x) { m_q.push(x); }

    int pop()
    {
        // 这里的处理是将队尾元素移动到队头，其他元素的位置保持不变。这样能保证当前弹出的元素是符合栈语义的，其他元素仍然是队列语义，下一次 pop() 时再执行相同逻辑即可。
        int n = m_q.size();
        for (int i = 0; i < n - 1; ++i)
        {
            auto e = m_q.front();
            m_q.pop();
            m_q.push(e);
        }

        int res = m_q.front();
        m_q.pop();


        return res;
    }

    int top()
    {
        int res = pop();
        // 保证队列语义，将弹出的元素重新加入队列，保持队列顺序不变。
        m_q.push(res);


        return res;
    }

    bool empty() { return m_q.empty(); }


private:

    // 只需要一个队列就够了，思路就是每次 pop() 的时候都把前面的元素出队列然后放到末尾去，这样最后进来的就在队头了，并且其他的顺序不变，下次重复相同的操作即可。
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


int main()
{
}
