#include <iostream>
using namespace std;

// 升序序列
// 这个用这个数最小的下标
int _binary_search1(int array[], int left, int right, int target) {
    while (left != right) {
        int mid = (left + right) / 2;
        // 最下下标，不包括这个数，左边所有的都小于这个数，右边的全部大于等于他
        // 思路就是：target左边的所有数小于他，那么如果mid对应的数小于他，那么target必然落在右边并且取不到mid!!!
        if (array[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    if (array[left] != target)
        return -1;
    return left;
}

// 这个用这个数最大的下标
int _binary_search2(int array[], int left, int right, int target) {
    while (left != right) {
        int mid = (left + right + 1) / 2;
        // 最下下标，不包括这个数，左边所有的都小于这个数，右边的全部大于等于他
        // 思路就是：target左边的所有数小于他，那么如果mid对应的数小于他，那么target必然落在右边并且取不到mid!!!
        if (array[mid] > target)
            right = mid - 1;
        else
            left = mid;
    }

    if (array[left] != target)
        return -1;
    return left;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    // 先输入数组
    int array[n];
    for (int i = 0; i < n; ++i)
        cin >> array[i];

    // 再依次输入询问的数
    int target[q];
    for (int i = 0; i < q; ++i)
        cin >> target[i];

    // 循环输出
    for (int i = 0; i < q; ++i) {
        int Left = _binary_search1(array, 0, n - 1, target[i]);
        int Right;
        if (Left == -1)
            Right = -1;
        else
            Right = _binary_search2(array, 0, n - 1, target[i]);
        cout << Left << ' ' << Right << endl;
    }

    return 0;
}
