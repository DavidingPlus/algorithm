/*
 * @lc app=leetcode.cn id=523 lang=cpp
 * @lcpr version=30404
 *
 * [523] 连续的子数组和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    bool checkSubarraySum(std::vector<int> &nums, int k)
    {
        int n = nums.size();

        std::vector<int> preSum(1 + n, 0);
        for (int i = 1; i <= n; ++i) preSum[i] = preSum[i - 1] + nums[i - 1];

        // 如果这里再用两层循环，会超时。
        // 子数组总和为 k 的倍数，等价于两个前缀和之差是 k 的倍数，
        // 也就等价于这两个前缀和 % k 相等。
        // 因此用一个哈希表存储前缀和 % k 的值及其索引，就能快速查询是否满足条件了。
        std::unordered_map<int, int> um;

        // preSum[i] 表示原数组前 i 个元素的和，因此 preSum[0] 表示原数组第一个元素之前的边界。从 i = 0 开始遍历，是为了记录这个边界；否则会漏掉从原数组下标 0 开始的子数组。例如整个数组对应 preSum[n] - preSum[0]，必须保留 preSum[0] 才能计算这个长度。因此不能改为从 i = 1 开始遍历。
        for (int i = 0; i <= n; ++i)
        {
            if (um.count(preSum[i] % k))
            {
                if (i - um[preSum[i] % k] >= 2) return true;
            }
            else
            {
                um[preSum[i] % k] = i;
            }
        }


        return false;
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
// [23,2,4,6,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n13\n
// @lcpr case=end

// @lcpr case=start
// [0]\n1\n
// @lcpr case=end

 */
