#include <iostream>
using namespace std;
#include <string>
#include <vector>

// 判断A是否大于B 1大于 -1小于 0等于
int cmp(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size())
        return A.size() > B.size() ? 1 : -1;

    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i])
            return A[i] > B[i] ? 1 : -1;
    // 相同
    return 0;
}

// C=A-B
// 这个函数一定保证了A不小于B
vector<int> sub(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    int num = 0;
    for (int i = 0; i < A.size(); ++i) {
        num += A[i];
        if (i < B.size())
            num -= B[i];

        C.push_back((num + 10) % 10);  // 这把正负数两种情况综合在一起
        if (num < 0)
            num = -1;
        else
            num = 0;
    }

    // 消去前置0
    while (C.back() == 0)
        C.pop_back();

    return C;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> A, B;  // a="123456"

    // 大整数存储 从低位开始存储
    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');  // A =[6,5,4,3,2,1]
    for (int i = b.size() - 1; i >= 0; --i)
        B.push_back(b[i] - '0');

    vector<int> C;

    switch (cmp(A, B)) {
    case 1:
        C = sub(A, B);
        break;
    case -1:
        cout << '-';
        C = sub(B, A);
        break;
    case 0:
        C.push_back(0);
        break;
    }

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    cout << endl;

    return 0;
}
