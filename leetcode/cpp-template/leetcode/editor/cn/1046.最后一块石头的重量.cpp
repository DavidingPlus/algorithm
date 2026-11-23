/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 * @lcpr version=30404
 *
 * [1046] 最后一块石头的重量
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int lastStoneWeight(std::vector<int> &stones)
    {
        // 每次选出最重的两块石头，很容易想到使用大顶堆。
        std::priority_queue<int, std::vector<int>, std::less<int>> pq(stones.begin(), stones.end());

        while (pq.size() > 1)
        {
            int stone1 = pq.top();
            pq.pop();

            int stone2 = pq.top();
            pq.pop();

            if (std::abs(stone1 - stone2)) pq.push(std::abs(stone1 - stone2));
        }


        return pq.size() ? pq.top() : 0;
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
// [2,7,4,1,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
