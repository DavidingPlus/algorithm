/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class MyCircularDeque
{

public:

    MyCircularDeque(int k)
    {
        m_capacity = k;
        m_vec.resize(m_capacity);
    }

    bool insertFront(int value)
    {
        if (isFull()) return false;

        m_front = (m_front - 1 + m_capacity) % m_capacity;
        m_vec[m_front] = value;
        ++m_size;


        return true;
    }

    bool insertLast(int value)
    {
        if (isFull()) return false;

        m_vec[m_tail] = value;
        m_tail = (m_tail + 1) % m_capacity;
        ++m_size;


        return true;
    }

    bool deleteFront()
    {
        if (isEmpty()) return false;

        m_front = (m_front + 1) % m_capacity;
        --m_size;


        return true;
    }

    bool deleteLast()
    {
        if (isEmpty()) return false;

        m_tail = (m_tail - 1 + m_capacity) % m_capacity;
        --m_size;


        return true;
    }

    int getFront() const { return isEmpty() ? -1 : m_vec[m_front]; }

    int getRear() const { return isEmpty() ? -1 : m_vec[(m_tail - 1 + m_capacity) % m_capacity]; }

    bool isEmpty() const { return 0 == m_size; }

    bool isFull() const { return m_capacity == m_size; }


private:

    // 思路同 622 题。

    // m_front 指向当前队首元素，m_tail 指向队尾元素之后的下一个空位。
    // 但队列刚创建时为空，此时并不存在真正的队首，m_front = m_tail = 0
    // 只是初始游标，不能把这个 0 理解成已经存在的队首下标。
    //
    // 例如容量为 5 时：
    //   初始状态：m_front = 0，m_tail = 0，m_size = 0
    //   insertFront(10)：m_front 向前循环到 4，并把 10 写入下标 4
    //                   此时队列的逻辑内容是 [10]，队首就是下标 4
    //   insertLast(20)：把 20 写入下标 0，m_tail 移到 1
    //                   沿循环方向从下标 4 走到下标 0，逻辑顺序是 [10, 20]
    // 因此，空队列时 m_front = 0 只是约定；第一次从队首插入时先移动 m_front，
    // 正好可以在当前队首的前一个循环位置写入新元素。

    std::vector<int> m_vec;

    int m_capacity = 0, m_size = 0;

    int m_front = 0, m_tail = 0;
};

/**
 * Your MyCircularDeque object will be instantiated && called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end


int main()
{
}
