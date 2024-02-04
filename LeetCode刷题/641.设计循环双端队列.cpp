/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        v = vector<int>(k);
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        // 包含负数的情况，计算正确的index
        // 为了避免麻烦的判断，先全部变为正数再取模
        int index = ((front - 1) % capacity + capacity) % capacity;

        v[index] = value;
        --front;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        int index = (tail % capacity + capacity) % capacity;

        v[index] = value;
        ++tail;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        ++front;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        --tail;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return v[(front % capacity + capacity) % capacity];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return v[((tail - 1) % capacity + capacity) % capacity];
    }

    bool isEmpty() { return front == tail; }

    bool isFull() { return tail - front == capacity; }

private:
    // 思路和设计单端循环队列一样
    vector<int> v;
    // 由于可以前插，所以front和tail可以负数，负数取模会返回负数的取模值，加上capacity就是真实的下标，这一点区别需要注意
    int front = 0, tail = 0;
    int capacity = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
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
