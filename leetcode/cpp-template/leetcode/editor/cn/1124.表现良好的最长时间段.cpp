/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 * @lcpr version=30404
 *
 * [1124] 表现良好的最长时间段
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int longestWPI(std::vector<int> &hours)
    {
        int res = 0;
        int n = hours.size();

        // 也是元素转换的思路，大于 8 小时记为 1，小于 8 小时记为 -1。然后使用前缀和 + 哈希表即可。
        std::vector<int> preSum(1 + n, 0);
        std::unordered_map<int, int> um;
        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);

            // 依旧只存最左边的元素下标。
            if (!um.count(preSum[i])) um[preSum[i]] = i;
        }


        for (int i = 0; i <= n; ++i)
        {
            // 如果 preSum[i] 本身大于 0，那么它本身就是以 i 结尾的最大长度。
            if (preSum[i] > 0)
            {
                res = std::max(res, i);
            }
            // 如果 preSum[i] 小于 0，我们期望在前面尽可能靠左找到某个位置 j，使得 preSum[i] - preSum[j] > 0。
            // XXX 关键思路是前缀和相邻只能按照 +1 和 -1 变化，而前缀和的初始值是 0，因此当某个位置是负数例如 -3 的时候，现在向左变化，不管怎么变化，最后向左一定要最后要变为 0，也就是简化后一定会经过 0, -1, -2, -3 这样的区间，但我们的需求是找到 -4 或 -5 这样的值，他能存在的插入点只能是 0, -1, -2, -3, -4, -5, -4, -3 这样变化，因为最终向左要变成 0，因此必须有一个变化的过程。现在考虑最左边，如果取 -5，那么 -5 的左边一定能找到 -4，就不符合最左的条件了，因此只能取 -4。
            else
            {
                if (um.count(preSum[i] - 1)) res = std::max(res, i - um[preSum[i] - 1]);
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
// [9,9,6,0,6,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

 */
