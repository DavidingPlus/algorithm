/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30404
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <bits/stdc++.h>
// @lc code=start

class Solution
{

public:

    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // 由于是非递减顺序排列的数组，因此用双指针，需要考虑的就是双指针的移动问题。
        // 如果当前左右指针之和大于 target，左指针往右移动会导致相加值更大，左指针往右的解均不符合条件，因此此时需要右指针往左移。另外一种情况同理。

        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] > target)
            {
                --right;
            }
            else if (nums[left] + nums[right] < target)
            {
                ++left;
            }
            else
            {
                return {1 + left, 1 + right};
            }
        }


        return {};
    }
};
// @lc code=end


int main()
{
}


/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */
