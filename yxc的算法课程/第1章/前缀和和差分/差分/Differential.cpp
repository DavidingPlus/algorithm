#include <iostream>
using namespace std;

const int N = 100010;

int n, m, l, r, c;
int arr[N] = {0}, differ_arr[N] = {0};  // 第二个是差分数组

// 在l到r闭区间当中每个数加上c的操作
void __operate(int l, int r, int c) {
    differ_arr[l] += c;
    differ_arr[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        differ_arr[i] = arr[i] - arr[i - 1];
        // __operate(i, i, arr[i]);  // 上面一行相当于这一行
    }

    // 操作
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &l, &r, &c);
        __operate(l, r, c);
    }

    // 得到最终的结果再求一次前缀和即可
    for (int i = 1; i <= n; ++i) {
        arr[i] = arr[i - 1] + differ_arr[i];
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}
