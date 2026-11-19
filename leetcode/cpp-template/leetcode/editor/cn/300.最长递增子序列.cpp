/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

class Solution
{

public:

    int lengthOfLIS(std::vector<int> &nums)
    {
        int res = 1, n = nums.size();

        // 维护 dp[i] 是第 i 个元素结尾的最长递增子序列的长度（i - 1 是下标）。
        // 因为这个子序列不一定是连续的，因此前面每一项都有可能作为答案的一部分，即遍历前面每一项计算 dp[i]，状态转移方程到手。
        std::vector<int> dp(1 + n, 1);

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = 1;

            for (int j = 1; j < i; ++j)
            {
                if (nums[i - 1] > nums[j - 1]) dp[i] = std::max(dp[i], 1 + dp[j]);
            }

            res = std::max(res, dp[i]);
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
