/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        // 滑动窗口的思路，目的是找到所有满足条件的子数组，答案就呼之欲出。
        // 右指针先往右移动，找到第一个满足条件的区间，这时候右指针再往右移是肯定能满足条件的，因此把左指针往右移动，减小区间。因为我们需要找到长度最小的子数组，因为刚才右指针往右移动肯定不是答案，直到不满足条件，这就是目前为止的答案，继续将右指针往右移动重复操作即可。当然本算法的前提条件是所有的元素都是正数。

        int left = 0, right = 0;
        int res = std::numeric_limits<int>::max(), sum = 0;

        while (right < nums.size())
        {
            sum += nums[right++];

            while (left < right && sum >= target)
            {
                res = std::min(res, right - left);

                sum -= nums[left++];
            }
        }


        return std::numeric_limits<int>::max() == res ? 0 : res;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
