/**
 * @file MyRingBuffer.h
 * @brief MyRingBuffer类的头文件
 * @author lzx0626 (2065666169@qq.com)
 * @version 1.0
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023  电子科技大学
 *
 */

#ifndef _MYRINGBUFFER_H_
#define _MYRINGBUFFER_H_

#include <cstring>
#include <exception>
#include <format>
#include <iostream>

/**
 * @brief 定义我自己的RingBuffer类
 */
template <class value_type>
class MyRingBuffer {
public:
    /**
     * @brief 定义一些类型
     */
    using pointer = value_type*;
    using reference = value_type&;
    using constref = const value_type&;

public:
    /**
     * @brief 构造函数
     * @param capacity，可以给定数组的容量，有一个默认值是1024
     */
    MyRingBuffer(int capacity = INIT_CAP);

    /**
     * @brief 析构函数
     */
    ~MyRingBuffer();

    /**
     * @brief 拷贝构造
     * @param other
     */
    MyRingBuffer(const MyRingBuffer& other);

    /**
     * @brief 拷贝赋值
     * @param other
     * @return MyRingBuffer&
     */
    MyRingBuffer& operator=(const MyRingBuffer& other);

public:
    /**********最核心的两个API**********/

    /**
     * @brief 从RingBuffer中读取数据到out数组中，并返回读取到的字节数
     * @param  out，存放读取到的数据的数组
     * @return int，返回读取到的字节数
     */
    int read(pointer out);

    /**
     * @brief 将in数组中的数据写入到RingBuffer中，并返回写入字节的个数
     * @param  out，写入数据的源数组
     * @return int，返回实际写入的字节数
     */
    int write(pointer in);

    /**********工具函数**********/

    /**
     * @brief 清空整个结构
     */
    void clear();

    /**
     * @brief 返回可读的字节数量
     * @return int
     */
    int length() { return size; }

    /**
     * @brief 判断有无可读的数据
     * @return true 没有可读的数据
     * @return false 有可读的数据
     */
    bool isEmpty() { return 0 == size; }

private:
    /**
     * @brief 初始化
     */
    void _init(int capacity);

    /**
     * @brief 这里我们做一个小技巧，就是把输入的capacity给转化为2的指数，这样就可以用位运算代替%运算
     * @brief 这个函数的作用就是将输入的num转化为2的指数，比如输入12，返回16
     * @param  num
     * @return int
     */
    int _cellToPowerTwo(int num);

private:
    /**
     * 存放数据的数组
     */
    pointer buffer = nullptr;

    /**
     * @brief 读指针的位置
     */
    int r;

    /**
     * @brief 写指针的位置
     */
    int w;

    /**
     * @brief 数组的容量，我们的数组设置的是一个环形数组
     */
    int capacity;

    /**
     * @brief 用来替换效率低的%运算，用位运算求余数
     */
    int mask;

    /**
     * @brief 记录可以读取的字节数
     */
    int size;

    /**
     * @brief 定义默认的数组容量值
     */
    static const int INIT_CAP;
};

#endif
