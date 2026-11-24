/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30404
 *
 * [1143] 最长公共子序列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        // 本题目肯定是需要迭代取维护状态的，因为有两个字符串，不妨设两个指针 i 和 j 来代表二者遍历的状态，dp[i][j] 表示 text1 的前 i 个字符和 text2 的前 j 个字符，最长公共子序列的长度。为了维护初始条件，i 和 j 的含义是第 i 或 j 个元素，因为 dp[0][0] = 0 代表没有遍历字符串时的初始条件。

        int m = text1.size(), n = text2.size();

        std::vector<std::vector<int>> dp(1 + m, std::vector<int>(1 + n, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // XXX 好难理解的状态转移方程。
                // 从 dp[i - 1][j - 1] 推导 dp[i][j]：相当于尝试给两个前缀各加上一个末尾字符。
                // 如果两个末尾字符相同，就可以把这个字符接在最长公共子序列后面，长度加 1。
                // 如果两个末尾字符不同，它们不能用当前这两个末尾位置彼此匹配：
                // 1. 若最长公共子序列用了 text1 的末尾位置，就不能用 text2 的末尾位置，结果由 dp[i][j - 1] 表示。
                // 2. 若用了 text2 的末尾位置，则由 dp[i - 1][j] 表示。
                // 3. 若两个末尾位置都没用，结果已包含在 dp[i - 1][j - 1] 中；它不会超过上面两个状态。
                // 因此不相等时取 std::max(dp[i][j - 1], dp[i - 1][j])。
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }


        return dp[m][n];
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
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */
