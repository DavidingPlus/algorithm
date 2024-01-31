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
        // 快慢指针，快指针给慢指针赋值，慢指针只有在被赋值之后才会前进
        // 在这个过程中肯定是后面的填充前面的，不用担心前面的值被覆盖，因为在覆盖之前他们的值肯定已经前移了，最极端的情况，没有val的值，那就相当于每个位置自身赋值了一次
        int slow = 0, fast = 0;
        for (; fast != nums.size(); ++fast)
            if (val != nums[fast])
                nums[slow++] = nums[fast];
        return slow;
    }
};
// @lc code=end
