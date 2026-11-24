/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30404
 *
 * [121] 买卖股票的最佳时机
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int maxProfit(std::vector<int> &prices)
    {
        // 遍历 prices，遍历中时刻维护遇到的最低买入值，后面能卖出的值都和该买入值计算，直到找到最大利润。
        int cost = std::numeric_limits<int>::max(), res = 0;

        for (auto &price : prices)
        {
            // res 初始值为 0，price - cost 虽然包含了亏本的情况，但是不会影响答案。
            res = std::max(res, price - cost);
            cost = std::min(cost, price);
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
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
