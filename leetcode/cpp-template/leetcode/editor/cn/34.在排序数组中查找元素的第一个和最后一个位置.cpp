/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 左边界，即代表不小于 target 的第一个元素
    int leftBound(const std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                right = mid - 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // 注意题目要求的返回，这里需要检验一下是否越界并且 target 是否存在于数组中
        return (left <= nums.size() - 1 && target == nums[left]) ? left : -1;
    }

    // 有边界，即代表不大于 target 的最后一个元素
    int rightBound(const std::vector<int> &nums, int target)
    {
        // 同理
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return (right >= 0 && target == nums[right]) ? right : -1;
    }

    // 非递减数组
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        // 特判数组为空
        if (nums.empty()) return {-1, -1};

        return {leftBound(nums, target), rightBound(nums, target)};
    }
};

// @lc code=end
