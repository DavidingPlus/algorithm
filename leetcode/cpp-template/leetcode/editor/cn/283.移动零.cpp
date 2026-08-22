/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start



class Solution
{

public:

    // 快慢指针 + 末尾补 0。
    void moveZeroes(std::vector<int> &nums)
    {
        int fast = 0, slow = 0;

        for (; fast < nums.size(); ++fast)
        {
            if (0 != nums[fast]) nums[slow++] = nums[fast];
        }

        for (; slow < nums.size(); ++slow) nums[slow] = 0;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
