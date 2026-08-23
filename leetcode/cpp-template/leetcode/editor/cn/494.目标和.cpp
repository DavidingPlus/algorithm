/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=20003
 *
 * [494] 目标和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start




namespace std
{
    template <>
    struct hash<std::pair<int, int>>
    {
        // 哈希函数需要加上限定符 const，否则编译器会报错！
        std::size_t operator()(const std::pair<int, int> &p) const
        {
            return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
        }
    };
}


class Solution
{
public:

    // 解法 1：带 memo 的递归 dp
    // std::pair 中存放的是唯一标识某种情形的 left 和 target
    std::unordered_map<std::pair<int, int>, int> m_memo;

    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        return dp(nums, 0, target);
    }

    int dp(const std::vector<int> &nums, int left, int target)
    {
        if (nums.size() == left) return 0 == target;

        // 先查 memo，查不到递归并写入 memo
        std::pair<int, int> key = {left, target};

        if (0 == m_memo.count(key)) m_memo[key] = dp(nums, 1 + left, target - nums[left]) + dp(nums, 1 + left, target + nums[left]);


        return m_memo[key];
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
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
