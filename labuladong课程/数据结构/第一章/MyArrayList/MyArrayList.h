#ifndef _MYARRAYLIST_H_
#define _MYARRATLIST_H_

#include <cstring>
#include <exception>
#include <iostream>
#include <string>

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
    using constref = const value_type &;

public:
    /**
     * @brief 默认构造函数
     */
    MyArrayList();

    /**
     * @brief 带参构造
     * @param list，初始化列表
     */
    MyArrayList(std::initializer_list<value_type> list);

    /**
     * @brief 析构函数
     */
    ~MyArrayList();

    /**
     * @brief 带指针，需要些拷贝复制
     * @param array，需要拷贝复制的对象
     */
    MyArrayList<value_type> &operator=(const MyArrayList<value_type> &array);

    /**
     * @brief 带指针，需要写拷贝构造
     * @param array，需要拷贝构造的对象
     */
    MyArrayList(const MyArrayList<value_type> &array);

public:
    /***********增***********/
    /**
     * @brief 在index的位置插入一个元素
     * @param index，需要插入的位置，注意插入的位置是在缝里插入，所以pos==size的情况是合法的，意思就是在最后的位置插入
     * @param val，插入的元素的值
     */
    void insert(int index, constref val);

    /**
     * @brief 在数组末尾插入元素
     * @param val，插入的元素的值
     */
    void push_back(constref val);

    /***********删***********/
    /**
     * @brief 删除指定index位置处的元素并返回
     * @param index，需要删除的元素的下标
     * @return value_type类型的删除的元素的值
     */
    value_type remove(int index);

    /**
     * @brief 删除末尾的元素4
     * @return value_type类型的删除的元素的值
     */
    value_type pop_back();

    /***********改***********/
    /**
     * @brief 修改index位置的元素值为val
     * @param index，指定的需要修改的元素下标
     * @param val，修改过后的值
     * @return value_type类型的查询到的元素值
     */
    value_type set(int index, constref val);

    /***********查***********/
    /**
     * @brief 返回index位置处的元素值
     * @param index，指定需要查询的下标
     * @return value_type类型的查询到的元素值
     */
    value_type get(int index);

    /**
     * @brief 肯定需要重载中括号运算符啊，只不过这个中括号返回的是引用，里面的值可以修改
     */
    reference operator[](int index);

    /***********工具函数***********/
    /**
     * @brief 定义回调函数的类型
     */
    using call_back = void(reference val);

    /**
     * @brief 给用户提供遍历容器的接口，怎么遍历通过回调函数指定
     * @param call，函数作为回调函数
     */
    void tranverse(call_back call);

    /**
     * @brief 提供返回容器元素个数的接口
     * @return size_t类型的数组元素个数
     */
    size_t size();

    /**
     * @brief 判断容器是否为空
     */
    bool isEmpty();

private:
    /**
     * @brief 对数组进行初始化
     */
    void _init();

    /**
     * @brief 对数组重新进行扩容
     * @param cap，扩充到的大小，一般采取两倍扩容
     */
    void _resize(size_t cap);

    /**
     * @brief 写一个函数专门用作进行index下标的异常处理，防止代码冗杂
     * @param index，需要检查的下标
     * @param func_name，函数名称
     */
    void _check_index(int index, std::string func_name);

private:
    /**
     * @brief 存储数据的数组，这里放一根指针
     */
    pointer data;

    /**
     * @brief 存储数组的大小
     */
    size_t _size;

    /**
     * @brief 存储数组的容量
     */
    size_t capacity;

    /**
     * @brief 定义数组默认初始的容量
     */
    static size_t INIT_CAP;
};

#endif
