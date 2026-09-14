/*
 * @lc app=leetcode.cn id=3959 lang=cpp
 * @lcpr version=30404
 *
 * [3959] 判定好整数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    bool checkGoodInteger(int n)
    {
        int digitSum = 0, squareSum = 0;

        while (n)
        {
            digitSum += n % 10;
            squareSum += (n % 10) * (n % 10);

            n /= 10;
        }


        return squareSum - digitSum >= 50;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here

    std::cout << solution.checkGoodInteger(19) << std::endl;
}


/*
// @lcpr case=start
// 1000
\n
// @lcpr case=end

// @lcpr case=start
// 19
\n
// @lcpr case=end

 */
