#include <iostream>

// greatest common divisor 最大公约数
long long gcd(long long val1, long long val2)
{
    // 辗转相除法
    // a 被除数 b 除数
    auto a = std::max(val1, val2), b = std::min(val1, val2);
    while (0 != a % b)
    {
        auto newB = a % b;
        a = b;
        b = newB;
    }
    return b;
}

// least common multiple 最小公倍数
long long lcm(long long val1, long long val2)
{
    return val1 / gcd(val1, val2) * val2; // 乘法在除法之前进行，可以避免溢出
}

int main()
{
    int mod[50] = {0, 0, 1, 2, 1, 4, 5, 4, 1, 2, 9, 0, 5, 10, 11, 14, 9, 0, 11, 18, 9, 11, 11, 15, 17, 9, 23, 20, 25, 16, 29, 27, 25, 11, 17, 4, 29, 22, 37, 23, 9, 1, 11, 11, 33, 29, 15, 5, 41, 46};

    // 从第一个数开始，比如只考虑第一个数，满足条件的最小值是 3 ，后续要满足就加上 2 ，现在我加入下一个数 3 ，先找到在步长 2 的基础上能满足这二者的最小的数是 5，想要继续满足，需要更新步长为 2 和 3 的最小公倍数 6 才行
    // 可能会思考到这种问题，就是前面已经加入的数字得出的结果已经能够满足后面的数字，但是要记住，上面数学归纳法的前提是满足前面 n 个数的最小值，所以即使满足 n+1 ，整体也是不满足的，因此不必担心，这也是一种数学归纳法和动态规划的思想
    long long ans = 3, step = 2; // 初始状态
    for (int i = 3; i < 50; ++i)
    {
        // 加入新的数，首先在原步长上进行判断
        while (mod[i] != ans % i)
            ans += step;
        // 更新步长
        step = lcm(step, i);
    }

    std::cout << ans << '\n'; // 2022040920220409

    return 0;
}
