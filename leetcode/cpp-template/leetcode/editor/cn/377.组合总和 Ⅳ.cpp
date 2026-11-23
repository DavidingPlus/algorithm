/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30404
 *
 * [377] 组合总和 Ⅳ
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    // 完全背包问题。
    // int combinationSum4(std::vector<int> &nums, int target)
    // {
    //     // 注意题目中提到的顺序不同的序列被视作不同的组合，因此本题目求的是排列而不是组合，如果用 dp[i][j] 代表使用前 i 个元素凑出 j 的数量，这样得到的状态转移方程的最后结果是组合数，因为我们无法得知前 dp[i - 1][] 的信息，无法知道是由哪些数组成的，其中有多少个相同的数，对应的排列数是多少。
    //     // 但这很明显是一个完全背包的板子，所以需要修改 dp 的语义。因为本题和排列强相关，我们需要将元素的位置考虑进 dp，可以定义 dp[i][j] 是以第 i 个元素结尾的序列凑出 j 的序列的数量。因为我们强调了 i 元素结尾的信息，因此能记录所有的排列。
    //     // 但从这个板子来看，有三层循环 i，j，k，其中 k 代表 i 元素确定结尾以后，所有的其他元素当作倒数第二个数的排列情况，需要求和。即 dp[i][j] = sum(dp[k][j - nums[i - 1]])，这个数其实是可以被预先算出来的，但是遍历到 i 的时候需要所有的元素的信息，所以需要先遍历 j 而不是 i。

    //     int m = nums.size(), n = target;

    //     // 过程中可能越界，但答案不越界，依旧 unsigned int 起手。
    //     std::vector<std::vector<unsigned int>> dp(1 + m, std::vector<unsigned int>(1 + n, 0));
    //     dp[0][0] = 1;

    //     // 额外定义 total 数组存储 sum(dp[k][j - nums[i]])。
    //     std::vector<unsigned int> total(1 + n, 0);
    //     total[0] = 1;

    //     for (int j = 1; j <= n; ++j)
    //     {
    //         // 用前 0 个元素凑出 j 的序列的数量是 0，初始条件已初始化为 0，因为循环中要用到 nums[i - 1]，因此不能 int i = 0 开始。
    //         // dp[0][j] = 0;

    //         for (int i = 1; i <= m; ++i)
    //         {
    //             if (j - nums[i - 1] >= 0) dp[i][j] = total[j - nums[i - 1]];

    //             total[j] += dp[i][j];
    //         }
    //     }


    //     return total[n];
    // }

    // 空间复杂度优化版本。
    int combinationSum4(std::vector<int> &nums, int target)
    {
        int m = nums.size(), n = target;

        std::vector<unsigned int> total(1 + n, 0);
        total[0] = 1;

        for (int j = 1; j <= n; ++j)
        {
            for (int i = 1; i <= m; ++i)
            {
                if (j - nums[i - 1] >= 0) total[j] += total[j - nums[i - 1]];
            }
        }


        return total[n];
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
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */
