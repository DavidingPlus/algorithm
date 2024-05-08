/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// @lc code=start
class Solution
{
public:
    // 解法1：暴力
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (target == nums[i] + nums[j])
                    return {i, j};

        return {};
    }
};
// @lc code=end
