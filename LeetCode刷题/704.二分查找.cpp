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
        // 设置为开区间
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (target == nums[mid])
                return mid;
            if (nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }

        return -1;
    }
};
// @lc code=end
