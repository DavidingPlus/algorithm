/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    void moveZeroes(std::vector<int> &nums)
    {
        // 快慢指针。
        int slow = 0;

        for (int fast = 0; fast < nums.size(); ++fast)
        {
            if (0 != nums[fast]) nums[slow++] = nums[fast];
        }

        // 末尾补 0。
        for (; slow < nums.size(); ++slow) nums[slow] = 0;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
