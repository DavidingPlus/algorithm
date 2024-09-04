/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int removeDuplicates(std::vector<int> &nums)
    {
        // 快慢指针，将前面的值重新填充
        int fast = 0, slow = 0;
        for (; fast < nums.size(); ++fast)
        {
            // 我们找每一组的最后一个，这种情况下会遗漏必然填入最终数组的数组末尾元素，补上即可
            if (fast != nums.size() - 1 && nums[fast] != nums[fast + 1]) nums[slow++] = nums[fast];
        }
        // 本题数据数组不可能为空，因此不用特判
        nums[slow++] = nums[nums.size() - 1];

        return slow;
    }
};

// @lc code=end
