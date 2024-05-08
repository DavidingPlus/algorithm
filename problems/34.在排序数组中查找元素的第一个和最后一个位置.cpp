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

// 升序!
// 二分查找实现查找左边界和右边界
// 为了左右统一，这里采用双闭区间
int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 与下面做同步，right减了不影响left的判断
        if (target == nums[mid])
            right = mid - 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    // 那left做判断，可能越界
    if (left < 0 or left >= nums.size() or target != nums[left])
        return -1;
    return left;
}

int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 这里有个问题是会卡住
        // 解决办法是让mid+1，然后下面用right判断!!!!
        if (target == nums[mid])
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (right < 0 or right >= nums.size() or target != nums[right])
        return -1;
    return right;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target),
                right_bound(nums, target)};
    }
};
// @lc code=end
