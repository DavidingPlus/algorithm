#include <iostream>
using namespace std;

const int N = 100010;
int n, num;

// lowbit操作的应用
int lowbit(int x) {
    return x & -x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);

        // 每次减去这个数的最后一位1，直到变为0
        int res = 0;
        while (num) {
            num -= lowbit(num);
            ++res;
        }
        cout << res << ' ';
    }

    return 0;
}
