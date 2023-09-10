#ifndef _MYARRAYLIST_H_
#define _MYARRATLIST_H_

#include <cstring>
#include <iostream>

/**
 * @brief 我自己的MyArrayList类，元素类型传入一个模板
 */
template <class value_type>
class MyArrayList {
public:
    /**
     * @brief 定义一些类型
     */
    using pointer = value_type *;
    using reference = value_type &;

public:
    /**
     * @brief 默认构造函数
     */
    MyArrayList();

    /**
     * @brief 带参构造
     */
    MyArrayList(std::initializer_list<value_type> list);

    /**
     * @brief 析构函数
     */
    ~MyArrayList();

    /**
     * @brief 带指针，需要些拷贝复制
     */
    MyArrayList<value_type> &operator=(const MyArrayList<value_type> &array);

    /**
     * @brief 带指针，需要写拷贝构造
     */
    MyArrayList(const MyArrayList<value_type> &array);

public:
    /**
     * @brief 在数组末尾插入元素
     */
    void push_back(const reference val);

    /**
     * @brief 遍历函数的接口，怎么遍历通过回调函数指定
     */
    using call_back = void(reference val);

    void tranverse(call_back call);

private:
    /**
     * @brief 对数组进行初始化
     */
    void _init();

    /**
     * @brief 对数组重新进行扩容
     */
    void resize(int cap);

private:
    /**
     * @brief 存储数据的数组，这里放一根指针
     */
    value_type *data;

    /**
     * @brief 存储数组的大小
     */
    size_t size;

    /**
     * @brief 存储数组的容量
     */
    size_t capacity;

    /**
     * @brief 定义数组默认初始的容量
     */
    size_t INIT_CAP = 1;
};

#endif
