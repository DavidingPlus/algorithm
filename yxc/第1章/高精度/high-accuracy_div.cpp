#include <deque>
#include <iostream>
#include <string>
using namespace std;

pair<deque<int>, int> div(const deque<int>& A, const int& b) {
    deque<int> C;
    int num = 0;

    // 思路：就按照一般除法的思路走就行了
    for (int i = 0; i < A.size(); ++i) {
        num += A[i];
        C.push_back(num / b);
        num = 10 * (num % b);
    }

    // 去除前置0 比如 1234除以11
    // 关于商为0，就两种情况，一是被除数是0，二是被除数小于除数，保证不把0处理完就好了
    // 这时的num就是除下的余数，经过最后一次还乘以了10，不管是0还是小于是一样的
    while (C.front() == 0 && C.size() > 1)
        C.pop_front();

    return make_pair(C, num / 10);
}

// a很长 b很短
int main() {
    string a;
    int b;

    cin >> a >> b;

    deque<int> A;
    // 出发是从高位开始除，所以顺着存储
    for (int i = 0; i < a.size(); ++i)
        A.push_back(a[i] - '0');

    auto Pair = div(A, b);
    auto C = Pair.first;          // 商的deque表示
    int remainder = Pair.second;  // 余数

    for (int i = 0; i < C.size(); ++i)
        cout << C[i];
    cout << endl;

    cout << remainder << endl;

    return 0;
}
