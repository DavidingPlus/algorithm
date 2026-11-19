/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    // XXX 01 背包问题。

    // 滚动数组优化空间复杂度版本。
    bool canPartition(std::vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        for (auto &e : nums) sum += e;
        if (sum & 1) return false;

        int target = sum / 2;
        std::vector<bool> dp(1 + target, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
        {
            std::vector<bool> tmp(1 + target, false);

            for (int j = 1; j <= target; ++j)
            {
                tmp[j] = dp[j] |
                         (j - nums[i - 1] >= 0 && dp[j - nums[i - 1]]);
            }

            std::swap(dp, tmp);
        }


        return dp[target];
    }


    // bool canPartition(std::vector<int> &nums)
    // {
    //     // 转化一下思路，分割成两个子集，使得元素和相等，就是能否找到一个子集，使得这个子集和是数组元素和的一半。
    //     // 因此可以先做数组元素和为奇数的特判。
    //     int n = nums.size();

    //     int sum = 0;
    //     for (auto &e : nums) sum += e;
    //     if (sum & 1) return false;

    //     // 现在需要找是否存在一个子集，使得是数组元素和的一半。换句话说就是任意取 nums 中的元素，最后能否凑到某个值。这就是经典的 01 背包问题。
    //     // 如果维护 dp[j] 代表能否凑出 j，按照零钱兑换的思路，应该遍历每个 num 然后迭代状态。但是 01 背包中每个元素最多使用一次，就会丢失状态了。虽然先遍历 num 再遍历 j 能够解决，但是理解起来不够直观，因此干脆直接用 01 背包的板子了。

    //     // 01 背包维护一个二维 dp[i][j]，状态含义是只使用前 i 个数，能否凑出和 j。对于 dp[i][j]，分为选和不选 nums[i - 1] 两种情况：
    //     // 1. 不选 nums[i - 1]，则 dp[i][j] = dp[i - 1][j]；
    //     // 2. 选 nums[i - 1]，前提是 j >= nums[i - 1]，此时 dp[i][j] = dp[i - 1][j - nums[i - 1]]。
    //     // 初始化：dp[i][0] = true，表示不选任何数就能凑出 0；

    //     int target = sum / 2;
    //     std::vector<std::vector<bool>> dp(1 + n, std::vector<bool>(1 + target, false));
    //     dp[0][0] = true;

    //     for (int i = 1; i <= n; ++i)
    //     {
    //         for (int j = 1; j <= target; ++j)
    //         {
    //             dp[i][j] = dp[i - 1][j] |
    //                        (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]]);
    //         }
    //     }


    //     return dp[n][target];
    // }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
