#include <iostream>
using namespace std;
#include <string>
#include <vector>

int judge_Bigger(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size())
        return A.size() > B.size() ? 1 : -1;
    // size相同，从末尾开始往前走，第一个不同就可以判断了

    auto iterA = A.rbegin();
    auto iterB = B.rbegin();
    while ((iterA != A.rend()) && (*iterA == *iterB)) {
        ++iterA;  // 注意这里是rbegin!!!重载了++运算符!!!
        ++iterB;
    }

    if (iterA == A.rend())
        return 0;  // 返回-1表示相同

    return *iterA > *iterB ? 1 : -1;
}

// C=A-B
// 这里先保证A不小于B
vector<int> sub(const vector<int>& A, const vector<int>& B, int is_bigger) {
    // 先判断是否相同
    if (is_bigger == 0)
        return vector<int>{0};

    if (is_bigger == -1)
        return sub(B, A, 1);

    vector<int> C;
    int num = 0;

    for (int i = 0; i < A.size(); ++i) {
        // 先把数拿进来，注意num是包含了上一次的借位了的，看后面
        num += A[i];
        if (i < B.size())
            num -= B[i];

        // 存入数值
        if (num < 0) {  // 借位
            num += 10;
            C.push_back(num);
            num = -1;
        } else {
            C.push_back(num);
            num = 0;
        }
    }

    // 如果高位是0则pop掉
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

    int is_bigger = judge_Bigger(A, B);

    // 小的情况下先输出一个-号
    if (is_bigger == -1)
        cout << '-';

    auto C = sub(A, B, is_bigger);

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    cout << endl;

    return 0;
}
