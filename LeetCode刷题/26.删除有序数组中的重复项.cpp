/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <iostream>
using namespace std;
#include <vector>

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 快慢指针
        // 让快指针在前面探路，找到一个不重复的就赋值给满指针的位置，然后后移，直到遍历完
        int slow = 0, pre = __INT_MAX__;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (pre != nums[fast]) {
                nums[slow++] = nums[fast];
                pre = nums[fast];
            }
        }

        // slow的位置是期望被填入的新位置，因此就是size大小
        return slow;
    }
};
// @lc code=end
