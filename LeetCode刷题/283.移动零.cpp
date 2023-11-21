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
        // 快慢指针
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (0 != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        // 把0补上
        for (; slow < nums.size(); ++slow)
            nums[slow] = 0;
    }
};
// @lc code=end
