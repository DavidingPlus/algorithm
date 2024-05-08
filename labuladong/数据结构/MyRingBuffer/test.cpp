/**
 * @file test.cpp
 * @brief MyRingBuffer的测试文件
 * @author lzx0626 (2065666169@qq.com)
 * @version 1.0
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023  电子科技大学
 *
 */

#include <iostream>
using namespace std;
#include "MyRingBuffer.h"

namespace TestMyRingBuffer {

void test_constructor() {
    MyRingBuffer<int> r1(10);

    // 测试拷贝构造和赋值
    auto r2 = r1;
    auto r3(r1);

    // MyRingBuffer<int>(-1);  // 测试数组大小不合适
}

}  // namespace TestMyRingBuffer

int main() {
    TestMyRingBuffer::test_constructor();

    return 0;
}
