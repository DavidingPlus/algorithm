/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

#include "_listnode.h"


// @lc code=start
class MyLinkedList
{

public:

    MyLinkedList() : m_dummyHead(new ListNode(-1, nullptr)) {}

    int get(int index)
    {
        if (index < 0 || index >= m_size) return -1;

        auto pMove = m_dummyHead->next;
        for (int i = 0; i < index; ++i) pMove = pMove->next;

        return pMove->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(m_size, val); }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > m_size) return;

        auto pMove = m_dummyHead;
        for (int i = 0; i < index; ++i) pMove = pMove->next;

        // 有了 dummyHead 以后，转化为在 pMove 后面插入
        ListNode *newNode = new ListNode(val);

        newNode->next = pMove->next;
        pMove->next = newNode;

        ++m_size;
    }

    void deleteAtIndex(int index)
    {
        // 同上，一样的道理
        if (index < 0 || index >= m_size) return;

        auto pMove = m_dummyHead;
        for (int i = 0; i < index; ++i) pMove = pMove->next;

        pMove->next = pMove->next->next;

        --m_size;
    }


private:

    ListNode *m_dummyHead = nullptr;

    int m_size = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// @lc code=end
