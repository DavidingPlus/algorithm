#ifndef _MYLINKEDLIST_H_
#define _MYLINKEDLIST_H_

#include <exception>
#include <iostream>
#include <vector>

/**
 * @brief 我自己的MyArrayList类，元素类型传入一个模板
 */
template <class value_type>
class MyLinkedList {
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
    MyLinkedList();

    /**
     * @brief 带参构造函数
     * @param list，初始化列表
     */
    MyLinkedList(std::initializer_list<value_type> list);

    /**
     * @brief 拷贝构造函数(深拷贝)
     */
    MyLinkedList(MyLinkedList<value_type>& other);

    /**
     * @brief 拷贝赋值函数(深拷贝)
     */
    MyLinkedList& operator=(MyLinkedList<value_type>& other);

    /**
     * @brief 析构函数
     */
    ~MyLinkedList();

public:
    /***********增***********/
    /**
     * @brief 在某个位置的前面插入元素
     * @param index，插入元素的下标，我们给用户提供的是在某个元素前面插入，但是我们自己实现的时候要注意缝隙下标
     * @param val，插入的元素的值
     */
    void insert_before(int index, constref val);

    /**
     * @brief 在某个元素的后面插入元素
     * @param index，插入元素的下标，还是元素下标
     * @param val，插入的元素的值
     */
    void insert_after(int index, constref val);

    /**
     * @brief 在尾部插入元素
     * @param val，插入的元素的值
     */
    void push_back(constref val);

    /**
     * @brief 在头部插入元素
     */
    void push_front(constref val);

    /***********删***********/
    /**
     * @brief 删除指定位置的元素
     * @param index，删除位置的下标
     * @return value_type类型的删除的元素的值
     */
    value_type remove(int index);

    /**
     * @brief 从头部弹出一个元素
     * @return value_type类型的弹出的元素的值
     */
    value_type pop_front();

    /**
     * @brief 从尾部弹出一个元素
     * @return value_type类型的弹出的元素的值
     */
    value_type pop_back();

    /***********改***********/
    /**
     * @brief 修改指定下标的元素的值
     * @param index，指定的下标
     * @param val，想要修改成为的值
     */
    void set(int index, constref val);

    /***********查***********/
    /**
     * @brief 重载[]运算符，方便用户使用
     */
    reference operator[](int index);

    /**
     * @brief 得到指定下标的元素
     * @param index，想得到的位置的下标
     * @return value_type类型的元素的值
     */
    value_type get(int index);

    /**
     * @brief 得到头部的元素
     * @return value_type类型的元素的值
     */
    value_type front();

    /**
     * @brief 得到尾部的元素
     * @return value_type类型的元素的值
     */
    value_type back();

    /***********工具函数***********/
    /**
     * @brief 定义回调函数别名
     */
    using call_back = void(reference);

    /**
     * @brief 定义给用户的遍历容器的接口
     */
    void traverse(call_back call);

    /**
     * @brief 得到容器的大小
     * @return size_t类型的容器大小
     */
    size_t size();

    /**
     * @brief 判断容器是否为空
     * @return bool类型的真假
     */
    bool isEmpty();

    /**
     * @brief 清空容器
     */
    void clear();

private:
    /**
     * @brief 定义结点类型
     */
    struct node {
        value_type val;
        struct node* next = nullptr;
        struct node* prior = nullptr;
    };

    /**
     * @brief 定义结点指针类型别名
     */
    using nodeptr_t = node*;

    /**
     * @brief 定义头结点和尾结点
     */
    nodeptr_t head, tail;

    /**
     * @brief 定义链表长度
     */
    size_t length;

private:
    /**
     * @brief 对链表的元素进行初始化
     */
    void _init();

    /**
     * @brief 写一个函数专门用作进行index下标的异常处理，防止代码冗杂
     * @param index，需要检查的下标
     * @param func_name，函数名称
     */
    void _check_index(int index, std::string func_name);

    /**
     * @brief 在某个缝隙下标的位置处插入元素，所以下标可以等于length
     * @param index，缝隙下标的值
     * @param val，插入的元素的值
     *
     */
    void _link_before(int index, constref val);

    /**
     * @brief 给一个下标定位到下标位置的结点(内部调用，一定会保证不会越界)
     * @param index，下标(从元素第一个值开始计算，不是头结点)
     * @return nodeptr_t类型的指针，指向这个结点
     */
    nodeptr_t get_node(int index);
};

#endif
