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
        // 快慢指针，快指针跑得快，所以不用担心慢指针的修改会造成影响
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (fast + 1 != nums.size() and nums[fast] == nums[fast + 1])
                ++fast;
            else
                nums[slow++] = nums[fast++];
        }
        return slow;
    }
};
// @lc code=end
