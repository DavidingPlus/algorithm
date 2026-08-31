/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30404
 *
 * [373] 查找和最小的 K 对数字
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        std::vector<std::vector<int>> res;

        // 从枚举的角度来讲，遍历 nums1 中的每个元素 i，去和 nums2 中的每个元素 j 组成一对，求出和最小的 k 对。那么可以根据 nums1 的元素分成 nums1.size() 组，每组中有 nums2.size() 个元素。最后的答案相当于是求所有组中和最小的 k 对，自然能联想到前面的合并 k 个链表的思路。

        // 使用优先性队列（这里用最小堆）存储 {i, j}。
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::function<bool(const std::pair<int, int> &, const std::pair<int, int> &)>>
            pq([&nums1, &nums2](const std::pair<int, int> &p1, const std::pair<int, int> &p2)
               {
                   return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second]; //
               });

        // 这里有一个小优化，由于两个数组本身已经是非递减排列的，因此如果 nums1.size() > k，nums1 中超出 k 的部分必然不需要放入队列了，他们后续的值也不可能是答案。
        for (int i = 0; i < std::min(static_cast<int>(nums1.size()), k); ++i) pq.push({i, 0});

        while (!pq.empty() && k--)
        {
            auto e = pq.top();
            pq.pop();

            res.push_back({nums1[e.first], nums2[e.second]});

            if (1 + e.second < nums2.size()) pq.push({e.first, 1 + e.second});
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
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */
