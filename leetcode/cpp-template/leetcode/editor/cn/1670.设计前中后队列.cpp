/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

class FrontMiddleBackQueue
{

public:

    FrontMiddleBackQueue() {}

    void pushFront(int val) { m_dq.emplace_front(val); }

    void pushMiddle(int val)
    {
        int mid = m_dq.size() / 2;
        m_dq.insert(m_dq.begin() + mid, val);
    }

    void pushBack(int val) { m_dq.emplace_back(val); }

    int popFront()
    {
        if (m_dq.empty()) return -1;

        int res = m_dq.front();
        m_dq.pop_front();
        return res;
    }

    int popMiddle()
    {
        if (m_dq.empty()) return -1;

        int mid = m_dq.size() & 1 ? m_dq.size() / 2 : m_dq.size() / 2 - 1;

        int res = m_dq[mid];
        m_dq.erase(m_dq.begin() + mid);
        return res;
    }

    int popBack()
    {
        if (m_dq.empty()) return -1;

        int res = m_dq.back();
        m_dq.pop_back();
        return res;
    }


private:

    // 因为要执行 push_front 和 push_back 操作，使用双端队列。
    std::deque<int> m_dq;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated && called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end


int main()
{
}
