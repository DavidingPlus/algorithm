/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    int pivotIndex(std::vector<int> &nums)
    {
        preSum.resize(1 + nums.size(), 0);
        for (int i = 1; i <= nums.size(); ++i) preSum[i] = preSum[i - 1] + nums[i - 1];

        for (int i = 1; i <= nums.size(); ++i)
        {
            if (preSum[i - 1] == preSum[nums.size()] - preSum[i]) return i - 1;
        }


        return -1;
    }

    std::vector<int> preSum;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
