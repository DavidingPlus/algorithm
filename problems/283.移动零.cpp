/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    void moveZeroes(std::vector<int> &nums)
    {
        // 快慢指针 + 末尾补 0
        int fast = 0, slow = 0;
        for (; fast < nums.size(); ++fast)
        {
            if (0 != nums[fast])
            {
                nums[slow++] = nums[fast];
            }
        }
        for (; slow < nums.size(); ++slow)
        {
            nums[slow] = 0;
        }
    }
};

// @lc code=end
