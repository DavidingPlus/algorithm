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
        // 那就是把其他元素前移，再在末尾补0
        // 双指针
        int slow = 0, fast = 0;
        for (; fast < nums.size(); ++fast) {
            // 最后一个无论是不是0都进行赋值，因为slow出来的位置在后面，如果对0不赋值，那么原位置如果不是0就出问题了
            if (nums.size() - 1 == fast || 0 != nums[fast])
                nums[slow++] = nums[fast];
        }
        // 填充0
        for (; slow < nums.size(); ++slow)
            nums[slow] = 0;
    }
};
// @lc code=end
