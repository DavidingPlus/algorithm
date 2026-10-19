/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30404
 *
 * [56] 合并区间
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        // 主要是需要先排序一次，这样后续的处理非常简单。思路见 56.png。

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &lhs, const std::vector<int> &rhs)
                  {
                      return lhs.front() < rhs.front(); //
                  });

        std::vector<std::vector<int>> res;
        res.emplace_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            auto &last = res.back();

            if (intervals[i].front() <= last.back())
            {
                last.back() = std::max(last.back(), intervals[i].back());
            }
            else
            {
                res.emplace_back(intervals[i]);
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
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */
