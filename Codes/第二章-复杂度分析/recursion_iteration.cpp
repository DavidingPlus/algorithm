#include <iostream>
using namespace std;

using value_type = long long;

const value_type N = 1e3;

// 分别拿递归和迭代实现fibo数列的求解

// 迭代
value_type fibo1(value_type n) {
    if (1 == n or 2 == n)
        return 1;

    value_type num1 = 1, num2 = 1;
    for (value_type i = 3; i <= n; ++i) {
        value_type tmp = num2;
        num2 += num1;
        num1 = tmp;
    }
    return num2;
}

// 递归
value_type memo[N + 10] = {0};

value_type fibo2(value_type n) {
    if (1 == n or 2 == n)
        return 1;

    // 做一个备忘录记录
    if (0 == memo[n])
        memo[n] = fibo2(n - 1) + fibo2(n - 2);

    return memo[n];
}

// 可以考虑立即函数(consteval)，但是参数必须是一个常量，所以我们这里用变量模板吧，当然我们需要告诉是个编译期常量(constexpr)
template <size_t N>
constexpr value_type fibo3 = fibo3<N - 1> + fibo3<N - 2>;

// 做特化
template <>
constexpr value_type fibo3<1> = 1;

template <>
constexpr value_type fibo3<2> = 1;

int main() {
    std::cout << fibo1(60) << std::endl;
    std::cout << fibo2(60) << std::endl;
    std::cout << fibo3<60> << std::endl;

    return 0;
}
