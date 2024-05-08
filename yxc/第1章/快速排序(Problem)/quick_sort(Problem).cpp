#include <iostream>
using namespace std;

void swap(int& val1, int& val2) {
    int val = val1;
    val1 = val2;
    val2 = val;
}

// 升序排序
// 这个代码遇到大量的数据的时候还是会出问题，需要进一步修改
void quick_sort(int arr[], int left, int right) {
    // 递归出口
    if (left >= right)
        return;

    int base_value = arr[left];
    int i = left;  // 选择从left开始，可以避免 4 5 中不进入循环然后就交换的问题
    int j = right;

    // 左边找第一个比基准值大的，右边找第一个比基准值小的
    while (i != j) {
        // 顺序很重要，需要先移动右边的!!!!
        while (arr[j] >= base_value && i < j)
            --j;
        while (arr[i] <= base_value && i < j)
            ++i;
        // 要保证j大于i才能交换，否则是无效的
        if (j > i)
            swap(arr[i], arr[j]);
    }
    // 将基准值归位，上面循环弹出的条件是相同，所以两个值相同
    swap(arr[left], arr[j]);

    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i)
        cin >> array[i];

    quick_sort(array, 0, n - 1);

    for (auto val : array)
        cout << val << ' ';
    cout << endl;

    return 0;
}
