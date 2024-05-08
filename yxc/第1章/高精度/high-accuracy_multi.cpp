#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mul(const vector<int>& A, const int& b) {
    // 如果这里 b == 0会出现前置0问题
    if (b == 0)
        return vector<int>{0};

    vector<int> C;

    // 思路：让b去乘以A的每一位，然后记录下每次的进位，然后把进位与上一级相加，该位的值就是这个值mod10
    // 与一般的思路不同，这个是把位数小的数放在前面!!!
    int num = 0;
    for (int i = 0; i < A.size(); ++i) {
        num += A[i] * b;
        C.push_back(num % 10);
        num /= 10;
    }

    // 保存首位
    C.push_back(num);

    // 消除前置0 例子 2*3 不加上面输出 06
    while (C.back() == 0)
        C.pop_back();

    return C;
}

// a很长 b很短
int main() {
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    cout << endl;

    return 0;
}
