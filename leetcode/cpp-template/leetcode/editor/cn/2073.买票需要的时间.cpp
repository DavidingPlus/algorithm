/*
 * @lc app=leetcode.cn id=2073 lang=cpp
 * @lcpr version=30404
 *
 * [2073] 买票需要的时间
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int timeRequiredToBuy(std::vector<int> &tickets, int k)
    {
        // 我们从队列的角度思考。每个人一次只能买一张票，然后就排到队列尾部重新排队。
        // 那对于位置 k 的人，他前面的人如果一直买票的话，到 k 买完的时候最多买 tickets[k] 张票。当然如果前面的人不用买这么多张票，他就买自己的票离开即可。对他后面的人同理，最多买 tickets[k] - 1 张票。

        int res = 0;

        for (int i = 0; i < tickets.size(); ++i)
        {
            if (i <= k)
            {
                res += std::min(tickets[i], tickets[k]);
            }
            else
            {
                res += std::min(tickets[i], tickets[k] - 1);
            }
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
// [2,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,1]\n0\n
// @lcpr case=end

 */
