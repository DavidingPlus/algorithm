/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 升序数组
    int search(vector<int>& nums, int target) {
        // 注意二分查找基本框架的细节
        int left = 0, right = nums.size() - 1;  // 查找指定元素的时候，使用闭区间，可以化解边界问题

        // 这里是等号，因为我们用的是闭区间
        while (left <= right) {
            int mid = left + (right - left) / 2;  // 这么写防止加起来越界
            if (target == nums[mid])
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }

        return -1;
    }
};
// @lc code=end
