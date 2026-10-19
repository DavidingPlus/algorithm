/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30404
 *
 * [53] 最大子数组和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int maxSubArray(std::vector<int> &nums)
    {
        // 主要要考虑清楚为什么能使用线性 dp。详见 53.png。

        int dp = nums[0], res = dp;

        for (int i = 1; i < nums.size(); ++i)
        {
            dp = std::max(dp + nums[i], nums[i]);
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
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
