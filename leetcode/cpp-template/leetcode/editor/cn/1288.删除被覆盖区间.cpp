/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 * @lcpr version=30404
 *
 * [1288] 删除被覆盖区间
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:


    int removeCoveredIntervals(std::vector<std::vector<int>> &intervals)
    {
        // 本题思路完全同 56 题。

        // XXX 排序规则需要修改一下，为了兼容起点相同但是终点不同的情况，这种情况也可能出现覆盖。例如 [1,2],[1,3]，这时应让 [1,3] 先出现，再接受 [1,2]，这样能正常走覆盖逻辑，也就是降序排序。
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &lhs, const std::vector<int> &rhs)
                  {
                      return lhs.front() == rhs.front()
                                 ? lhs.back() > rhs.back()
                                 : lhs.front() < rhs.front(); //
                  });

        auto last = intervals.begin();
        for (auto it = 1 + intervals.begin(); it != intervals.end();)
        {
            if (it->front() >= last->front() && it->back() <= last->back())
            {
                // 用 it 接受 erase 返回值，it 指向修改后的数组结构的下一个位置，也就是原本删除位置的下一个元素，不用在 ++it。
                it = intervals.erase(it);
            }
            else
            {
                last = it++;
            }
        }


        return intervals.size();
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
// [[1,4],[3,6],[2,8]]\n
// @lcpr case=end

/*
// @lcpr case=start
// [[1,4],[3,6],[2,8]]\n
// @lcpr case=end

/*
// @lcpr case=start
// [[52141,92589],[52991,93486],[46321,59199],[51955,78788],[18533,23127]]\n
// @lcpr case=end

// @lcpr case=start
// [[14041,32641],[24914,51477],[4983,81235],[62018,77987],[31523,32192],[74196,96194],[16126,52652],[59901,67707],[36502,51366],[56437,86744]]\n
// @lcpr case=end

 */
