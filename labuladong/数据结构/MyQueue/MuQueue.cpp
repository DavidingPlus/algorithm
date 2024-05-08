#include "MyQueue.h"

// 模板显式实例化
template class MyQueue<int>;

/**
 * @brief 对类内成员函数的实现
 */

template <class value_type>
MyQueue<value_type>::MyQueue(MyQueue<value_type>& other) {
    *this = other;
}

template <class value_type>
MyQueue<value_type>& MyQueue<value_type>::operator=(MyQueue<value_type>& other) {
    list = other.list;

    return *this;
}

template <class value_type>
void MyQueue<value_type>::push(constref val) {
    list.push_back(val);
}

template <class value_type>
value_type MyQueue<value_type>::pop() {
    value_type val = list.pop_front();

    return val;
}

template <class value_type>
value_type MyQueue<value_type>::peek() {
    return list.front();
}

template <class value_type>
bool MyQueue<value_type>::isEmpty() {
    return list.isEmpty();
}
