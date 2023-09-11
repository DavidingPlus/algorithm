#ifndef _MYDEQUE_H_
#define _MYDEQUE_H_

#include <iostream>

#include "MyLinkedList.h"

/**
 * @brief 我自己的双端队列，底层用我自己的链表实现
 */
template <class value_type>
class MyDeque {
public:
    /**
     * @brief 定义一些类型
     */
    using pointer = value_type*;
    using reference = value_type&;
    using constref = const value_type&;

public:
    /**
     * @brief 默认构造函数
     */
    MyDeque() = default;

    /**
     * @brief 默认析构函数
     */
    ~MyDeque() = default;

    /**
     * @brief 还是写一个拷贝构造吧
     * @param other，另一个拷贝给我的对象
     */
    MyDeque(MyDeque<value_type>& other);

    /**
     * @brief 相应的，拷贝赋值
     * @param other，另一个拷贝给我的对象
     * @return MyDeque&类型对象，返回自身
     */
    MyDeque<value_type>& operator=(MyDeque<value_type>& other);

    /**
     * @brief 带参的构造函数
     * @param list，传入的初始化序列
     */
    MyDeque(std::initializer_list<value_type> list);

private:
    /**
     * @brief 底层维护一个我自己的数组(复合)
     */
    MyLinkedList<value_type> array;
};

#endif
