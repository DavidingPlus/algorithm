/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30404
 *
 * [70] 爬楼梯
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int climbStairs(int n)
    {
        memo.resize(1 + n, -1);
        memo[0] = 1, memo[1] = 1;


        return dp(n);
    }

    int dp(int n)
    {
        // 可能导致 memo 越界的情况（n == 0 或者 n == 1）已由主函数初始化过了，直接在这里返回即可。
        if (-1 != memo[n]) return memo[n];

        memo[n] = dp(n - 1) + dp(n - 2);


        return memo[n];
    }


    std::vector<int> memo;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
