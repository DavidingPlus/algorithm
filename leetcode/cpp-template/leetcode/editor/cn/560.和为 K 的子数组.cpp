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
        int res = 0, n = nums.size();

        // XXX 本题的数据有负数，因此不能贸然采用滑动窗口的思路，但可以借鉴前缀和 + 哈希表的思路。
        // 为什么使用前缀和 + 哈希表？首先，题目要求求子数组的和，如果我们想在 O(n) 的时间复杂度内求出答案，就必须想办法在遍历到下标 i 的时候得到它前面数组和的一些信息。参考线性 DP 的思路，我们维护以 i 为结尾的子数组的这个状态，这样从全局来看，所有的情况都能被处理到，因为任何一个随机子数组都可以被放进这个状态集合，从局部来看，遍历到 i 的时候，只用考虑 i 前面的数组，使用前缀和就能快速计算 i 前面的数组的和。因此，题目的思路就变为遍历到 i 时，计算以 i 结尾的子数组且和为 k 的个数，自然而然就会想到用哈希表维护前缀和到（前面部分）这个前缀和出现过的次数的映射。

        std::vector<int> preSum(1 + n, 0);

        // 哈希表的键是某个位置的前缀和，值是前面部分这个前缀和出现过的次数。
        // 我们每次都用新进来的元素与前面部分比较，这样对新来的元素，前面部分在前面的循环中自己处理过了，后面部分在后续的循环中也会逐步处理，因此不会漏掉。
        std::unordered_map<int, int> um;
        // 遍历数组前，此时还没累加任何元素，前缀和就是 0，代表前缀和为 0 的数组出现过 1 次。
        // 例如 nums = {3}、k = 3：i = 0 先记录前缀 0；i = 1 查找 3 - 3 = 0，得到答案为 1。如果直接从 1 开始又没有初始化 um[0]，这个例子就会漏掉唯一的答案，也是为了后面的遍历服务。
        um[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];

            // 遍历到 i 时哈希表的状态应是除开他的前面部分的信息，若先加入 i 的信息再计算结果，答案可能包含 i 本身的影响，这是不对的。

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
