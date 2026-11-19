/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30404
 *
 * [152] 乘积最大子数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int maxProduct(std::vector<int> &nums)
    {
        // 按照惯例，维护一个 dp 数组代表以 i 结尾的乘积最大子数组的值，可分为前面部分和不带前面部分两种情况。子数组可以在当前位置重新开始，所以不能只把当前数乘到前一个状态上。不带前面部分很简单，就是 nums[i] 本身。带前面部分需要分解子问题，具体如下：
        // 当 nums[i] == 0 时，dp[i] = 0，这个不用想。当 nums[i] > 0 时，dp[i] = dp[i - 1] * nums[i - 1]，因为 nums[i] 不会导致 dp[i - 1] 的符号发生变化，因此结果是可以传递的。问题来了，当 nums[i] < 0 时，dp[i] 和 dp[i - 1] 的符号是反过来的。假设 dp[i - 1] 是 10，nums[1] 是 -2，这样算出来的结果不是乘积最大子数组，因为 dp[i - 1] 可以取更小的值，这样得到的结果更大。
        // 那怎么办呢？额外新增一个 dp 数组用于维护乘积最小子数组的值，就可以了。

        int n = nums.size();

        std::vector<int> dpMax(n, std::numeric_limits<int>::min()), dpMin(n, std::numeric_limits<int>::max());
        // 记得要初始化！
        dpMax[0] = nums[0], dpMin[0] = nums[0];

        int res = dpMax[0];

        for (int i = 1; i < n; ++i)
        {
            if (0 == nums[i])
            {
                dpMax[i] = 0, dpMin[i] = 0;
            }
            else if (nums[i] > 0)
            {
                dpMax[i] = std::max(nums[i], nums[i] * dpMax[i - 1]);
                dpMin[i] = std::min(nums[i], nums[i] * dpMin[i - 1]);
            }
            else
            {
                dpMax[i] = std::max(nums[i], nums[i] * dpMin[i - 1]);
                dpMin[i] = std::min(nums[i], nums[i] * dpMax[i - 1]);
            }

            res = std::max(res, dpMax[i]);
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
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

/*
// @lcpr case=start
// [-2]\n
// @lcpr case=end

 */
