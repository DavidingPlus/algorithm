/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=20003
 *
 * [494] 目标和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

// 解法 1：变式 01 背包问题。每位只能取 + 或者 - 号，但是题目的 target 可能为负数，因此需要转换。一个 target 能对应一组取 + 号的序列，也就能对应这组取 + 号序列的和。整个数组的总和是 sum（题目的提示都特别告诉 sum 了），(sum + target) / 2 就是只取 + 号序列的和。因此问题变为了纯正 01 背包问题，- 号代表的含义变成了不取。
class Solution
{

public:

    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto &num : nums) sum += num;

        // XXX 根据 sum 和 target 的语义，sum + target 的和必然是非负偶数，如果是负数或奇数，必然无解。
        if ((sum + target) < 0 || (sum + target) & 1) return 0;

        int m = nums.size(), n = (sum + target) >> 1;

        std::vector<int> dp(1 + n, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; ++i)
        {
            std::vector<int> tmp(1 + n, 0);

            for (int j = 0; j <= n; ++j)
            {
                tmp[j] = dp[j];

                if (j - nums[i - 1] >= 0) tmp[j] += dp[j - nums[i - 1]];
            }

            std::swap(dp, tmp);
        }


        return dp[n];
    }
};


// 解法 2：带 memo 的递归 dp。

// namespace std
// {
//     template <>
//     struct hash<std::pair<int, int>>
//     {
//         // 哈希函数需要加上限定符 const，否则编译器会报错！
//         std::size_t operator()(const std::pair<int, int> &p) const
//         {
//             return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
//         }
//     };
// }


// class Solution
// {

// public:

//     // std::pair 中存放的是唯一标识某种情形的 left 和 target。
//     std::unordered_map<std::pair<int, int>, int> m_memo;

//     int findTargetSumWays(std::vector<int> &nums, int target)
//     {
//         return dp(nums, 0, target);
//     }

//     int dp(const std::vector<int> &nums, int left, int target)
//     {
//         if (nums.size() == left) return 0 == target;

//         // 先查 memo，查不到递归并写入 memo。
//         std::pair<int, int> key = {left, target};

//         if (0 == m_memo.count(key)) m_memo[key] = dp(nums, 1 + left, target - nums[left]) + dp(nums, 1 + left, target + nums[left]);


//         return m_memo[key];
//     }
// };

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

// @lcpr case=start
// [1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n-1000\n
// @lcpr case=end

 */
