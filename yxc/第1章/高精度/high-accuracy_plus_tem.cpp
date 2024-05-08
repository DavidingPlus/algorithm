#include <iostream>
using namespace std;
#include <string>
#include <vector>

// C=A+B
vector<int> add(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    int num = 0;

    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        // 这样就巧妙的把数都进去了，还不用分段考虑
        if (i < A.size())
            num += A[i];
        if (i < B.size())
            num += B[i];

        // 存入C
        C.push_back(num % 10);
        // 计算进位留给下一次
        num /= 10;
    }

    // 最后出来的进位不要忘了
    if (num)
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
