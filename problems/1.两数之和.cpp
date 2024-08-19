/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1 + i; j < n; ++j)
            {
                if (target == nums[i] + nums[j]) return {i, j};
            }
        }

        return {};
    }
};

// @lc code=end
