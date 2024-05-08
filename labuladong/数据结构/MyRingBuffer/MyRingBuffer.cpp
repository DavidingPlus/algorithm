/**
 * @file MyRingBuffer.cpp
 * @brief MyRingBuffer类的源文件
 * @author lzx0626 (2065666169@qq.com)
 * @version 1.0
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023  电子科技大学
 *
 */

#include "MyRingBuffer.h"

/**
 * @brief 模板显式实例化
 */
template class MyRingBuffer<int>;

/**
 * @brief 初始化类内静态变量
 */
template <class value_type>
const int MyRingBuffer<value_type>::INIT_CAP = 1024;

/**
 * @brief 以下是对类内函数的实现
 */
template <class value_type>
MyRingBuffer<value_type>::MyRingBuffer(int capacity) {
    _init(capacity);
}

template <class value_type>
MyRingBuffer<value_type>::~MyRingBuffer() {
    clear();
}

template <class value_type>
MyRingBuffer<value_type>::MyRingBuffer(const MyRingBuffer &other) {
    *this = other;
}

template <class value_type>
MyRingBuffer<value_type> &MyRingBuffer<value_type>::operator=(const MyRingBuffer &other) {
    // 检测自我赋值
    if (this == &other)
        return *this;

    capacity = other.capacity;
    mask = other.mask;
    r = other.r;
    w = other.w;
    size = other.size;

    // 杀死原来的
    delete[] buffer;
    // 创建新的
    buffer = new value_type[capacity];
    memcpy(buffer, other.buffer, sizeof(value_type) * size);

    return *this;
}

template <class value_type>
int MyRingBuffer<value_type>::read(pointer out) {
}

template <class value_type>
int MyRingBuffer<value_type>::write(pointer in) {
}

template <class value_type>
void MyRingBuffer<value_type>::clear() {
    delete[] buffer;

    r = 0, w = 0;
    size = 0;
    capacity = 0;
    mask = 0;
}

template <class value_type>
void MyRingBuffer<value_type>::_init(int capacity) try {
    if (capacity < 0)
        throw std::out_of_range(std::format("capacity {} is out of bounds.", capacity));

    // 初始化
    // 在这里我们把capacity给替换为2的次方，这样可以方便的用位运算代替%运算
    // 也就是 num % capacity == num & ( capacity - 1 )
    this->capacity = _cellToPowerTwo(capacity);
    mask = capacity - 1;

    r = 0, w = 0;
    size = 0;
    buffer = new value_type[capacity];
} catch (std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
    exit(-1);
}

template <class value_type>
int MyRingBuffer<value_type>::_cellToPowerTwo(int num) {
    // 这是私有成员，我给的数肯定是大于0的，所以这里就不判断了

    // 这是大佬的办法
    // --num;
    // num |= num >> 1;
    // num |= num >> 2;
    // num |= num >> 4;
    // num |= num >> 8;
    // num |= num >> 16;
    // ++num;

    // 我的办法
    int res = 1;
    while (res < num)
        res *= 2;

    return res;
}
