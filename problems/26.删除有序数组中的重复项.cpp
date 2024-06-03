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
        // 快慢指针，将前面的值重新填充
        int slow = 0, fast = 0;
        for (; fast != nums.size(); ++fast)
            if (nums.size() - 1 == fast || nums[fast] != nums[fast + 1])
                nums[slow++] = nums[fast];

        return slow;
    }
};
// @lc code=end
