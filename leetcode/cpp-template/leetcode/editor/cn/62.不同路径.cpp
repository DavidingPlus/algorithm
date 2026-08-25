/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start




class Solution
{

public:

    int uniquePaths(int m, int n)
    {
        std::vector<int> dp(n);
        // 将第一行纳入统一迭代推导出的合理的初始条件（相当于添加 -1 行）
        dp[0] = 1;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j) dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
