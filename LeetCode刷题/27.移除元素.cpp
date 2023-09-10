/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <iostream>
using namespace std;
#include <vector>

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 我们不用标准库，用快慢指针
        // 快指针往后走，遇到不是val的就往前赋值，直到结束
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast)
            if (val != nums[fast])
                nums[slow++] = nums[fast];

        return slow;
    }
};
// @lc code=end
