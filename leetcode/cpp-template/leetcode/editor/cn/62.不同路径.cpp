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
        // 使用滚动数组。
        // 这个初始条件是构造了第一行上面不存在的那一行，除了第一个元素路径数为 1 外，其他的数都为 0，这样才能使得本来应该初始化的第一行的结果是正确的。
        std::vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i)
        {
            std::vector<int> tmp(n, 0);

            for (int j = 0; j < n; ++j)
            {
                tmp[j] += dp[j];

                if (j) tmp[j] += tmp[j - 1];
            }

            std::swap(dp, tmp);
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
