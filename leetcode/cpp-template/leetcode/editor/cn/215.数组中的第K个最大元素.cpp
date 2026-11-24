/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30404
 *
 * [215] 数组中的第K个最大元素
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int findKthLargest(std::vector<int> &nums, int k)
    {
        // 使用大顶堆，插入时间复杂度是 O(log n)，查询时间复杂度是 O(1)。
        std::priority_queue<int, std::vector<int>, std::less<int>> pq(nums.begin(), nums.end());

        while (--k) pq.pop();


        return pq.top();
    }

    // labuladong 的思路：最小堆，只维护 k 个元素。
    // int findKthLargest(std::vector<int> &nums, int k)
    // {
    //     std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    //     for (auto &num : nums)
    //     {
    //         pq.emplace(num);

    //         if (pq.size() > k) pq.pop();
    //     }


    //     return pq.top();
    // }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [3,2,1,5,6,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,1,2,4,5,5,6]\n4\n
// @lcpr case=end

 */
