#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int arr[N];

void swap(int& val1, int& val2) {
    int val = val1;
    val1 = val2;
    val2 = val;
}

// 找到第k个数(升序)
// 这里的k是序号
int __quick_sort_k(int left, int right, int k) {
    // 递归出口
    if (left > right)
        return arr[left];

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

    // 然后判断j和k谁更大，如果j更大说明在左边，继续递归
    // 注意k是相对于left的坐标!!!
    if (j > k)
        return __quick_sort_k(left, j - 1, k);
    else if (j < k)
        // 注意这里k的相对变化
        return __quick_sort_k(j + 1, right, k + left - (j + 1));
    else  // 碰到一起那必然就是相同了
        return arr[j];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    cout << __quick_sort_k(0, n - 1, k - 1) << endl;

    return 0;
}
