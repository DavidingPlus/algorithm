/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        v = vector<int>(k);
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        v[tail % capacity] = value;
        ++tail;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        ++front;
        return true;
    }

    int Front() { return isEmpty() ? -1 : v[front % capacity]; }

    int Rear() { return isEmpty() ? -1 : v[(tail - 1) % capacity]; }

    bool isEmpty() { return front == tail; }

    bool isFull() { return tail - front == capacity; }

private:
    // 哪一个数组来存储就好了，记录front和tail指针即可，记得取模
    vector<int> v;
    int front = 0, tail = 0;  // front指向队头元素，tail指向队尾元素的下一个元素
    // 为了区分判断空和满，做这样的设计，允许tail和front的值超出数组边界，我们在调用方的时候取模即可（我们希望用户不要塞INTMAX的值进去就行，当然在算法题当中这是能满足的）

    int capacity = 0;  // 记录数组大小
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
