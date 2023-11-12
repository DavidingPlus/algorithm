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
        // 快慢指针
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (val == nums[fast])
                ++fast;
            else
                nums[slow++] = nums[fast++];
        }
        return slow;
    }
};
// @lc code=end
