/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <queue>

class MyStack {
public:
    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        // 移动让队尾元素到达对头，从头部开始出队列入队列
        for (int i = 0; i < q.size() - 1; ++i) {  // 移动size-1次
            int num = q.front();
            q.pop();
            q.push(num);
        }
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        int res = pop();
        q.push(res);  // 不能破坏原先的结构
        return res;
    }

    bool empty() { return q.empty(); }

private:
    // 只需要一个队列就够了
    // 思路就是每次pop的时候都把前面的元素出队列然后放到末尾去，这样最后进来的就在队头了，并且其他的顺序不变，下次重复相同的操作即可
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
