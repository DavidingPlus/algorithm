#include <iostream>
using namespace std;
#include <bitset>
#include <cmath>

// 请你实现一个函数，接受一个正整数 n，函数能够打印所有长度为 n 的二进制数。
// 例如输入n = 3，算法打印000 001 010 011 100 101 110 111，共2^3 = 8个结果。

// 我能想到这么写，但是这么写违背了函数的定义
template <size_t N>
void generateBinaryNumber_mine() {
    // 思考：如何和二叉树结合起来？(我没想到)
    for (int i = 0; i < pow(2, N); ++i)
        cout << bitset<N>(i) << ' ';
    cout << endl;
}

// 老师的方法
void generateBinaryNumber(int num) {
    // 思路见"思路.png"
}

int main() {
    int num;
    cin >> num;

    // generateBinaryNumber_mine<3>();

    generateBinaryNumber(num);

    return 0;
}
