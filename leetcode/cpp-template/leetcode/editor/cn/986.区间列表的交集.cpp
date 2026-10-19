/*
 * @lc app=leetcode.cn id=986 lang=cpp
 * @lcpr version=30404
 *
 * [986] 区间列表的交集
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> &firstList, std::vector<std::vector<int>> &secondList)
    {
        // 从暴力遍历的思路入手，就是找到每个 i 和每个 j 区间，求他们的交集。但由于现在是排好序的区间，因此可以通过边界条件人为移动 i 和 j 指针，排除肯定没有交集的区间，因此可以使用双指针的板子。

        std::vector<std::vector<int>> res;

        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int a1 = firstList[i].front(), a2 = secondList[j].front(),
                b1 = firstList[i].back(), b2 = secondList[j].back();

            // 判断交集是否存在并插入。
            int left = std::max(a1, a2), right = std::min(b1, b2);
            if (left <= right) res.push_back({left, right});

            // XXX 最重要的是指针移动规则。
            // 若 b1 <= b2，那么 secondList 的下个区间的 start 一定是大于 b1 的，这时二者必然没有交集，++i 才可能找到下一组答案，注意此时不能 ++j，因为 firstList 的下一个区间可能仍与当前 j 存在交集。反之同理分析可得 ++j。
            b1 <= b2 ? ++i : ++j;
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
// [[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,9]]\n[]\n
// @lcpr case=end

 */
