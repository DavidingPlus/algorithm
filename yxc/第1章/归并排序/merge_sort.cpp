#include <iostream>
using namespace std;

// 升序排序
void merge_sort(int array[], int left, int right) {
    // 递归出口
    if (left == right)
        return;

    int newarr[right - left + 1];
    int mid = (left + right) / 2;

    // 递归左右
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    // 合并 left 到 mid 下标的左半部分 和 mid+1 到 right 的右半部分
    int left_move = left;
    int right_move = mid + 1;
    int i = 0;
    while (left_move <= mid && right_move <= right) {
        if (array[left_move] <= array[right_move])
            newarr[i++] = array[left_move++];
        else
            newarr[i++] = array[right_move++];
    }
    // 然后处理剩余的部分
    if (left_move == mid + 1)  // 左边跑完了
        for (; right_move <= right; ++i, ++right_move)
            newarr[i] = array[right_move];
    else if (right_move == right + 1)
        for (; left_move <= mid; ++i, ++left_move)
            newarr[i] = array[left_move];

    // 然后copy数组即可
    for (i = 0; i < right - left + 1; ++i)
        array[left + i] = newarr[i];
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i)
        cin >> array[i];

    merge_sort(array, 0, n - 1);

    for (auto val : array)
        cout << val << ' ';
    cout << endl;

    return 0;
}
