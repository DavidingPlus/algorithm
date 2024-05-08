#include <iostream>
using namespace std;

// 整数二分 有序序列，这里是升序
int _binary_search(int array[], int left, int right, int target) {
    while (left != right) {
        // 注意这里两个模板的区别，如果更新的是 left = mid , 那么需要 +1 保证不死循环
        // 参考 1 2 查找 1
        // 如果更新条件是 right = mid，那么就不需要
        int mid = (left + right + 1) / 2;
        if (array[mid] <= target)
            left = mid;
        else
            right = mid - 1;
    }

    // 如果不存在值，那么最后依然区间缩小的时候依然会跳出，这个值不同那么就不是找到的值
    if (array[left] != target)
        return -1;
    return left;
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i)
        cin >> array[i];

    int num;
    cin >> num;
    int position = _binary_search(array, 0, n - 1, num);

    cout << position << endl;

    return 0;
}
