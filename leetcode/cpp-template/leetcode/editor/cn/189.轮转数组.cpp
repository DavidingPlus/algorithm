/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30404
 *
 * [189] 轮转数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    void rotate(std::vector<int> &nums, int k)
    {
        // 本题思路类似 151 题。
        // 如何通过 reverse 反转的思路模拟题目要求的轮转？先分别对子区间反转，再整体反转。

        k %= nums.size();

        reverseFromRange(nums, 0, nums.size() - k - 1);
        reverseFromRange(nums, nums.size() - k, nums.size() - 1);
        reverseFromRange(nums, 0, nums.size() - 1);
    }

    void reverseFromRange(std::vector<int> &nums, int left, int right)
    {
        while (left < right) std::swap(nums[left++], nums[right--]);
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
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
