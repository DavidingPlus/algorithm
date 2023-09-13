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
     * @param init_list，传入的初始化序列
     */
    MyDeque(std::initializer_list<value_type> init_list);

public:
    /********增********/
    /**
     * @brief 插入元素，这里提供的是缝隙下标
     * @param index，要插入的位置下标
     * @param val，需要插入的元素的值
     */
    void insert(int index, constref val);

    /**
     * @brief 在尾部插入元素
     * @param val，需要插入的元素的值
     */
    void push_back(constref val);

    /**
     * @brief 在头部插入元素
     * @param val，需要插入的元素的值
     */
    void push_front(constref val);

    /********删********/
    /**
     * @brief 删除指定下标的元素
     * @param index，需要删除元素的下标
     * @return value_type类型的删除的元素的值
     */
    value_type remove(int index);

    /**
     * @brief 从尾部弹出元素
     * @return value_type类型的删除的元素的值
     */
    value_type pop_back();

    /**
     * @brief 从头部弹出元素
     * @return value_type类型的删除的元素的值
     */
    value_type pop_front();

    /********查********/
    /**
     * @brief 重载[]运算符
     * @param index，指定的元素的下标
     * @return value_type类型的元素的引用
     */
    reference operator[](int index);

    /**
     * @brief 得到index出的元素的值，是右值
     * @param index，指定的元素的下标
     * @return value_type类型的值
     */
    value_type get(int index);

    /**
     * @brief 返回双端队列末尾的值
     * @return value_type类型的值
     */
    value_type back();

    /**
     * @brief 返回双端队列头部的值
     * @return value_type类型的值
     */
    value_type front();

    /********查********/
    /**
     * @brief 清空队列
     */
    void clear();

    /**
     * @brief 设置某个位置元素的值
     * @param index，需要设置元素的下标
     * @param val，需要修改为的值
     */
    void set(int index, constref val);

    /**
     * @brief 定义遍历需要的函数类型
     */
    using call_back = void(reference val);

    /**
     * @brief 定义遍历函数
     * @param call，访问的回调函数
     */
    void traverse(call_back call);

    /**
     * @brief 返回队列长度
     */
    size_t size();

private:
    /**
     * @brief 底层维护一个我自己的链表(复合)，长度在这里面记录了
     */
    MyLinkedList<value_type> list;
};

#endif
