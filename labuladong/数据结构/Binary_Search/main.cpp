#include <iostream>
using namespace std;
#include <vector>

// 搜索一个数(最基本的二分搜索)，注意代码中的细节
// 此算法的缺陷：只能得到目标值在数组中的某一个位置，如果目标值在数组中是连续的，可能没有办法找到左右边界
int binarysearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;  // 搜索一个数的时候使用闭区间，避免边界条件

    // 终止条件：left == right + 1
    while (left <= right) {                   // 对应的这里的条件就变成了小于等于
        int mid = left + (right - left) / 2;  // 为了防止加起来越界，这么写
        if (target == nums[mid])
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    return -1;
}

// 找到左边界，找到这个数的左边界
int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();  // 搜索区间边界的时候最好使用左闭右开的区间

    // 终止条件：left == right
    while (left < right) {  // 对应的这里的条件就变成了小于，等于是不合法的
        int mid = left + (right - mid) / 2;

        if (target == nums[mid])  // 等于不能说明就是答案的左边界，需要继续判断
            right = mid;
        else if (nums[mid] >= target)
            right = mid;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    return left;
}

// 找到右边界，找到这个数的有边界
int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - mid) / 2;

        if (target == nums[mid])
            left = mid + 1;
        else if (nums[mid] >= target)
            right = mid;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    return right - 1;  // 这里需要注意的是需要减1，因为我们的区间是右开
}

int main() {
    vector<int> v{0, 1, 2, 2, 2, 2, 2, 3, 4, 5};

    // 测试搜索一个数
    cout << binarysearch(v, -1) << endl
         << binarysearch(v, 2) << endl;

    cout << endl;

    // 测试搜索左边界
    cout << left_bound(v, -1) << endl
         << left_bound(v, 2) << endl;

    cout << endl;

    // 测试搜索右边界
    cout << right_bound(v, -1) << endl
         << right_bound(v, 2) << endl;

    return 0;
}

// 一些模板，用闭区间实现的
namespace Template {
// 二分查找实现查找左边界和右边界
int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;  // 这次我用闭区间

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
            right = mid - 1;  // 这里需要减1，防止死循环
        else if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    // 判断left的范围
    if (left < 0 || left >= nums.size())
        return -1;

    // 判断找到的值是否为预期值
    return target == nums[left] ? left : -1;
}

int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;  // 这次我用闭区间

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    // 判断left的范围
    if (right < 0 || right >= nums.size())
        return -1;

    // 判断找到的值是否为预期值
    return target == nums[right] ? right : -1;
}
}  // namespace Template
