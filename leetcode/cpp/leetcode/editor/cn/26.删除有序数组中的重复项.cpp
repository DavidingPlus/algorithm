/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start



class Solution
{

public:

    // 快慢指针，将前面的值重新填充。初始时，快指针和慢指针值相等，当快指针值和慢指针不同的时候，代表快指针遇到了新的元素，这时候应该替换慢指针后面的元素。
    int removeDuplicates(std::vector<int> &nums)
    {
        int fast = 0, slow = 0;

        for (; fast < nums.size(); ++fast)
        {
            if (nums[slow] < nums[fast]) nums[++slow] = nums[fast];
        }


        return 1 + slow;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
