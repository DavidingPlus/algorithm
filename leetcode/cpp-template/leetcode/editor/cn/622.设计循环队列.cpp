/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class MyCircularQueue
{

public:

    MyCircularQueue(int k)
    {
        m_capacity = k;
        m_vec.resize(m_capacity);
    }

    bool enQueue(int value)
    {
        if (isFull()) return false;

        m_vec[m_tail] = value;

        m_tail = (m_tail + 1) % m_capacity;
        ++m_size;


        return true;
    }

    bool deQueue()
    {
        if (isEmpty()) return false;

        m_front = (m_front + 1) % m_capacity;
        --m_size;


        return true;
    }

    int Front() { return isEmpty() ? -1 : m_vec[m_front]; }

    int Rear() { return isEmpty() ? -1 : m_vec[(m_tail - 1 + m_capacity) % m_capacity]; }

    bool isEmpty() { return 0 == m_size; }

    bool isFull() { return m_size == m_capacity; }


private:

    // 底层用数组模拟队列。
    std::vector<int> m_vec;

    // m_capacity 记录队列容量，m_size 记录队列当前大小。
    // 为什么需要 m_size 呢？考虑一个例子：m_front == m_tail，这种情况无法判断是 isEmpty() 还是 isFull()，需要额外存储 m_size 判断。
    int m_capacity = 0, m_size = 0;

    // m_front 指向队头元素，m_tail 指向队尾的下一个元素。
    int m_front = 0, m_tail = 0;
};


/**
 * Your MyCircularQueue object will be instantiated && called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end


int main()
{
    std::cout << (0 - 5) % 8 << std::endl;
}
