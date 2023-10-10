/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

// 代码模板可以记忆！

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

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target),
                right_bound(nums, target)};
    }
};
// @lc code=end
