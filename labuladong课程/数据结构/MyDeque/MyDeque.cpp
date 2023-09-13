#include "MyDeque.h"

// 显式实例化模板
template class MyDeque<int>;

/**
 * @brief 以下是对类内函数的实现
 */

template <class value_type>
MyDeque<value_type>::MyDeque(MyDeque<value_type>& other) {
    *this = other;
}

template <class value_type>
MyDeque<value_type>& MyDeque<value_type>::operator=(MyDeque<value_type>& other) {
    list = other.list;

    return *this;
}

template <class value_type>
MyDeque<value_type>::MyDeque(std::initializer_list<value_type> init_list) {
    for (auto& val : init_list)
        push_back(val);
}

template <class value_type>
void MyDeque<value_type>::insert(int index, constref val) {
    list.insert_before(index, val);
}

template <class value_type>
void MyDeque<value_type>::push_back(constref val) {
    insert(list.size(), val);
}

template <class value_type>
void MyDeque<value_type>::push_front(constref val) {
    insert(0, val);
}

template <class value_type>
value_type MyDeque<value_type>::remove(int index) {
    return list.remove(index);
}

template <class value_type>
value_type MyDeque<value_type>::pop_back() {
    return remove(list.size() - 1);
}

template <class value_type>
value_type MyDeque<value_type>::pop_front() {
    return remove(0);
}

template <class value_type>
typename MyDeque<value_type>::reference MyDeque<value_type>::operator[](int index) {
    return list[index];
}

template <class value_type>
value_type MyDeque<value_type>::get(int index) {
    return std::move((*this)[index]);
}

template <class value_type>
value_type MyDeque<value_type>::back() {
    return get(list.size() - 1);
}

template <class value_type>
value_type MyDeque<value_type>::front() {
    return get(0);
}

template <class value_type>
void MyDeque<value_type>::clear() {
    list.clear();
}

template <class value_type>
void MyDeque<value_type>::set(int index, constref val) {
    list.set(index, val);
}

template <class value_type>
void MyDeque<value_type>::traverse(call_back call) {
    list.traverse(call);
}

template <class value_type>
size_t MyDeque<value_type>::size() {
    return list.size();
}
