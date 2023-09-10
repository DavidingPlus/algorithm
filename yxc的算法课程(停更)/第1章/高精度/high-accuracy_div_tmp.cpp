#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 模板是为了适配加减法和乘法，从低位开始存储
vector<int> div(const vector<int>& A, const int& b, int& remainder) {
    vector<int> C;
    int num = 0;

    for (int i = A.size() - 1; i >= 0; --i) {
        remainder = remainder * 10 + A[i];
        C.push_back(remainder / b);
        remainder %= b;
    }
    reverse(C.begin(), C.end());

    // 去除前置0
    while (C.back() == 0 && C.size() > 1)
        C.pop_back();

    return C;
}

// a很长 b很短
int main() {
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    // 从低位开始存储
    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');

    int remainder = 0;  // 余数定义
    auto C = div(A, b, remainder);

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    cout << endl;
    cout << remainder << endl;

    return 0;
}
