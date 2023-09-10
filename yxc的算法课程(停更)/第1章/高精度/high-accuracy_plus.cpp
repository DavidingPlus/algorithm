#include <iostream>
using namespace std;
#include <string>
#include <vector>

// C=A+B
vector<int> add(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    bool is_carry = false;
    int i = 0, num = 0;

    for (; i < A.size() || i < B.size(); ++i) {
        if (i < A.size() && i < B.size())  // 先处理公共位数
            num = A[i] + B[i];
        else  // 这是公共位数完了之后处理单个的
            num = A.size() > B.size() ? A[i] : B[i];

        // 先判断上一次的is_carry看是否有进位
        if (is_carry)
            ++num;

        // 判断完之后将num重置
        is_carry = false;
        if (num >= 10) {
            num -= 10;
            is_carry = true;
        }
        C.push_back(num);
    }

    // 最后出来的进位不要忘了
    if (is_carry)
        C.push_back(1);

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

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    cout << endl;

    return 0;
}
