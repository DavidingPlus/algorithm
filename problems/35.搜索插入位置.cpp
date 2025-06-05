/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 升序数组，找到即找到第一个不小于 target 的位置
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                // 不小于 target 的第一个位置，那么在众多 target 的序列中，找到第一个，加上升序数组，区间应该往左收缩
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

        // 相等的情况下变动的是 right，考虑边界情况 mid 恰好就是不小于 target 的第一个位置，那么 right 变动了，答案就是 left，另一边的思路也是一样的
        // 这个题目很特殊，答案是插入的位置，因此 left 和 right 分别位于边界的时候恰好对应插入位置就在边界的情况，因此直接返回不需要做判断
        return left;
    }
};

// @lc code=end
