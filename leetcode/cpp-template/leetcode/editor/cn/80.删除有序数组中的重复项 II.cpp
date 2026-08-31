/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30404
 *
 * [80] 删除有序数组中的重复项 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int removeDuplicates(std::vector<int> &nums)
    {
        // 和 26 题思路一致，但增加一个 count 记录数字出现的次数。
        int slow = -1, fast = 0;
        int count = 0;

        for (; fast < static_cast<int>(nums.size()); ++fast)
        {
            // XXX 第一个元素，或者遇到了一个新数字：直接保留，并将当前数字的出现次数重置为 1。
            if (-1 == slow || nums[slow] < nums[fast])
            {
                nums[++slow] = nums[fast];
                count = 1;
            }
            // 当前数字和结果数组末尾数字相同，且出现次数还不到两次时保留。
            else if (nums[slow] == nums[fast] && count < 2)
            {
                nums[++slow] = nums[fast];
                ++count;
            }
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


/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
