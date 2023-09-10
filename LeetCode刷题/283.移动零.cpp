/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <iostream>
using namespace std;
#include <vector>

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 快慢指针，非0的往前填，然后把0补齐即可
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast)
            if (0 != nums[fast])
                nums[slow++] = nums[fast];

        for (; slow < nums.size(); ++slow)
            nums[slow] = 0;
    }
};
// @lc code=end
