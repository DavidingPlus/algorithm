/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <deque>

// TODO 后续自己用链表手搓一遍
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) { d.push_front(val); }

    void pushMiddle(int val) { d.insert(d.begin() + d.size() / 2, val); }

    void pushBack(int val) { d.push_back(val); }

    int popFront() {
        if (d.empty())
            return -1;

        int res = d.front();
        d.pop_front();
        return res;
    }

    int popMiddle() {
        if (d.empty())
            return -1;

        int res = d[d.size() & 1 ? d.size() / 2 : d.size() / 2 - 1];
        d.erase(d.begin() + ((d.size() & 1) ? d.size() / 2 : d.size() / 2 - 1));
        return res;
    }

    int popBack() {
        if (d.empty())
            return -1;

        int res = d.back();
        d.pop_back();
        return res;
    }

private:
    deque<int> d;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end
