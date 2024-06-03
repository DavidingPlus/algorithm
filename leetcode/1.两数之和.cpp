/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 1 + i; j < nums.size(); ++j)
            {
                if (target == nums[i] + nums[j])
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// @lc code=end
