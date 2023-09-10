#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

#include <iostream>

#include "MyLinkedList.h"

/**
 * @brief 我自己的栈，底层用双向链表维护
 */
template <class value_type>
class MyQueue {
public:
    /**
     * @brief 定义一些类型别名
     */
    using pointer = value_type*;
    using reference = value_type&;
    using constref = const value_type&;

public:
    /**
     * @brief 默认构造函数
     */
    MyQueue() = default;

    /**
     * @brief 默认析构函数
     */
    ~MyQueue() = default;

    /**
     * @brief 拷贝构造，由于list中含有指针，还是写一个吧(虽然我直到可以不用写)
     */
    MyQueue(MyQueue<value_type>& other);

    /**
     * @brief 对应的拷贝赋值
     */
    MyQueue<value_type>& operator=(MyQueue<value_type>& other);

public:
    /**
     * @brief 入栈
     * @param val，需要入栈的元素的值
     */
    void push(constref val);

    /**
     * @brief 弹栈
     */
    value_type pop();

    /**
     * @brief 返回栈顶元素的值
     * @return value_type类型栈顶元素的值
     */
    value_type peek();

    /**
     * @brief 判断是否为空
     * @return bool类型，空为真
     */
    bool isEmpty();

private:
    /**
     * @brief 底层采用composition(复合)维护一个双向链表
     */
    MyLinkedList<value_type> list;
};

#endif
