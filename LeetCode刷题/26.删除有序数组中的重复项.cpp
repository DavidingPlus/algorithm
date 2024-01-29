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
        int fast = 0, slow = 0;
        while (fast != nums.size()) {
            // 不管如何，最后一个位置的数是必然会拿进去的
            if (fast == nums.size() - 1 or nums[fast] != nums[fast + 1])
                nums[slow++] = nums[fast];
            ++fast;
        }
        return slow;
    }
};
// @lc code=end
