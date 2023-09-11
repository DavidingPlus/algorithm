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
    array = other.array;

    return *this;
}

template <class value_type>
MyDeque<value_type>::MyDeque(std::initializer_list<value_type> list) {
    ;
}
