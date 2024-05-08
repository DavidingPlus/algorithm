#include <iostream>
using namespace std;

double triple(double num) {
    return num * num * num;
}

double get_cubic_root(double num) {
    // 分两种情况，如果num>=1，那么三次方根的范围是在 [ 1,num )
    // 如果 0<=num < 1，那么三次方根的范围是在 ( num,1 ]
    double absnum = num;
    if (num < 0)
        absnum = -num;

    // 这个东西只能求正数的值!!!遇到负数求相反数的
    double left = absnum <= 1 ? absnum : 1;
    double right = absnum > 1 ? absnum : 1;

    // 逻辑一样，只是初值不同
    while (right - left > 1e-8) {
        double mid = (left + right) / 2;
        if (absnum > triple(mid))
            left = mid;
        else
            right = mid;
    }

    return num >= 0 ? left : -left;
}

int main() {
    double num;
    cin >> num;

    printf("%6lf\n", get_cubic_root(num));

    return 0;
}
