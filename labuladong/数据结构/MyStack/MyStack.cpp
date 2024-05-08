#include "MyStack.h"

// 模板显式实例化
template class MyStack<int>;

/**
 * @brief 对类内成员函数的实现
 */

template <class value_type>
MyStack<value_type>::MyStack(MyStack<value_type>& other) {
    *this = other;
}

template <class value_type>
MyStack<value_type>& MyStack<value_type>::operator=(MyStack<value_type>& other) {
    list = other.list;

    return *this;
}

template <class value_type>
void MyStack<value_type>::push(constref val) {
    list.push_back(val);
}

template <class value_type>
value_type MyStack<value_type>::pop() {
    value_type val = list.pop_back();

    return val;
}

template <class value_type>
value_type MyStack<value_type>::get() {
    return list.back();
}

template <class value_type>
bool MyStack<value_type>::isEmpty() {
    return list.isEmpty();
}
