/*
 * @lc app=leetcode.cn id=485 lang=cpp
 * @lcpr version=30404
 *
 * [485] 最大连续 1 的个数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    // 解法 1：滑动窗口。
    // int findMaxConsecutiveOnes(std::vector<int> &nums)
    // {
    //     int left = 0, right = 0;
    //     int res = 0;

    //     while (right < nums.size())
    //     {
    //         ++right;

    //         while (left < right && 0 == nums[right - 1]) ++left;

    //         res = std::max(res, right - left);
    //     }


    //     return res;
    // }

    // 解法 2：线性 DP。
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int dp = 0, res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            dp = nums[i] ? 1 + dp : 0;
            res = std::max(res, dp);
        }


        return res;
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
// [1,1,0,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1,0,1]\n
// @lcpr case=end

 */
