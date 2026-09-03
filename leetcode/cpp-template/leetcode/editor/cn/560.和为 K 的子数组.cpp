/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30404
 *
 * [560] 和为 K 的子数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int subarraySum(std::vector<int> &nums, int k)
    {
        int res = 0;

        // 本题的数据有负数，因此不能贸然采用滑动窗口的思路。
        // 仍然可以借鉴前缀和 + 哈希表的思路。
        int n = nums.size();

        std::vector<int> preSum(1 + n, 0);
        // 这个哈希表的键是某个位置的前缀和，值是前面部分这个前缀和出现过的次数。
        // 我们每次都用新进来的元素与前面部分比较，这样对新来的元素，前面部分在前面的循环中自己处理过了，后面部分在后续的循环中也会逐步处理，因此不会漏掉。
        std::unordered_map<int, int> um;

        for (int i = 1; i <= n; ++i) preSum[i] = preSum[i - 1] + nums[i - 1];

        for (int i = 0; i <= n; ++i)
        {
            // 满足条件的公式是 preSum[i] = preSum[j - 1] + k。
            if (um.count(preSum[i] - k)) res += um[preSum[i] - k];

            ++um[preSum[i]];
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
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */
