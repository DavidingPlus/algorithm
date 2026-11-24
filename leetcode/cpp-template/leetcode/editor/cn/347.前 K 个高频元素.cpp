/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30404
 *
 * [347] 前 K 个高频元素
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        // 基本思路：哈希表记录所有数的出现频率，再用堆找出频率前 k 的元素。
        std::unordered_map<int, int> um;
        for (auto &num : nums) ++um[num];

        using PairType = std::pair<int, int>;

        std::priority_queue<PairType,
                            std::vector<PairType>,
                            std::function<bool(const PairType &, const PairType &)>>
            pq([](const PairType &lhs, const PairType &rhs)
               { return lhs.second > rhs.second; });

        for (auto &p : um)
        {
            pq.push(p);

            if (pq.size() > k) pq.pop();
        }

        std::vector<int> res;
        while (!pq.empty()) res.emplace_back(pq.top().first), pq.pop();


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
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,3,1,3,2]\n2\n
// @lcpr case=end

 */
