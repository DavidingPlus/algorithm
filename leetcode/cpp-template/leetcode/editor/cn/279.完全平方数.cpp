/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30404
 *
 * [279] 完全平方数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int numSquares(int n)
    {
        // 题目要求 n 必须由完全平方数构成，也就是 n = a * 1 * 1 + b * 2 * 2 + c * 3 * 3 + ... 的这种模式。如何把 n 和前面的关系联系起来呢？
        // n 可以写为 n = 1 * 1 + ... 或 n = 2 * 2 + ... 的形式，这其实就有一点状态转移方程的意思了。使用 dp[x] 表示凑出 x 所需的最少平方数个数。任意一种凑出 i 的方案都至少包含一个平方数 j²；去掉它，剩下的部分至少需要 dp[i - j²] 个数。因此枚举所有 j² ≤ i，取 1 + dp[i - j²] 的最小值。这个递推也允许剩余部分继续使用 j²，所以重复项没有遗漏。我们继续考虑一下合理性。
        // 首先，n = 2 * 1 * 1 + ... 的模式是否可能被接受？其实不行，因为可以改写为 n = 1 * 1 + 1 * 1 + ... 后面两部分相加从语义上一定是大于等于 dp 数组对应的值的，因此后面这两部分可能只是其对应数据的某个子集而不是最优解，最优解一定是 dp 数组中的值。n = 1 * 1 + 2 * 2 + ... 同理不被接受。
        // 其次，n = 1 * 1 + ... 和 n = 2 * 2 + ... 的情况是否可能有重复？很可能，但是我们最后得到的答案是把这些值取最小值，所以就无所谓了，不影响最终的答案。
        // 最后，也是最重要的，为什么当前这一步拿走 j 需要枚举呢？因为我们不知道最佳解法里面包含的数，但我们知道可能包含 1，也可能不包含 1，如果包含 1，那就是 1 + dp[i - 1 * 1]，如果不包含 1，虽然我们无法直接通过正常的途径返回值，但是我们知道，一定包含了其他的完全平方数，因此可以遍历可能存在的每个 j，最后取最小值，就能涵盖包含每个数和不包含每个数的最终的最优解。

        std::vector<int> dp(1 + n, std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j) dp[i] = std::min(dp[i], 1 + dp[i - j * j]);
        }


        return dp[n];
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
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
