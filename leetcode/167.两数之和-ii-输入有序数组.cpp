/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int left = 0, right = numbers.size() - 1;

        while (left < right)
        {
            if (target == numbers[left] + numbers[right])
            {
                return {1 + left, 1 + right};
            }
            else if (numbers[left] + numbers[right] > target)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
