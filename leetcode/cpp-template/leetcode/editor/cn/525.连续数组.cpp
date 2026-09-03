/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    int findMaxLength(std::vector<int> &nums)
    {
        int res = 0;

        // 这个题目的思路需要转换一下，相同数量的 0 和 1 的最长连续子数组，为了快速判断某个区间是不是满足条件的，如果把 0 变成 -1，那么这个子数组的和就是 0，可以联想到前缀和。
        int n = nums.size();

        std::vector<int> preSum(1 + n, 0);
        for (int i = 1; i <= n; ++i) preSum[i] = preSum[i - 1] + (nums[i - 1] ? 1 : -1);

        // 对每一个位置的前缀和值，我们只记录它第一次出现的位置，也就是最靠左的位置。当后面再次出现相同的前缀和值时，两者之间的区间和为 0。固定右端点时，左端点越靠左，区间长度越长，所以必须使用最早的位置。
        // 使用哈希表记录前缀和到下标的映射。
        std::unordered_map<int, int> um;
        for (int i = 0; i <= n; ++i)
        {
            if (um.count(preSum[i]))
            {
                res = std::max(res, i - um[preSum[i]]);
            }
            else
            {
                um[preSum[i]] = i;
            }
        }


        return res;
    }
};


// 旧版代码。

// const int N = 1e5 + 10;

// class Solution
// {

// public:

//     int ret = 0;

//     std::unordered_map<int, int> um; // 存储前缀和和最小下标的哈希表

//     int findMaxLength(std::vector<int> &nums)
//     {
//         // 对这个问题进行一个转换，就是0和1数量相同
//         // 意思就是如果我把0替换为-1，这个连续子序列的和就为0，这就涉及到前缀和数组了

//         // 填充前缀和数组
//         // 注意在过程中将所有的0替换为-1
//         for (int i = 1; i <= nums.size(); ++i)
//             presum[i] = presum[i - 1] + ((0 == nums[i - 1]) ? -1 : 1);

//         // 现在我再从头开始，每次加入一个新的数就多出了前面的数到这个数的序列和，我们遍历找出最大的即可
//         for (int i = 0; i <= nums.size(); ++i)
//         {
//             // 这个地方的查询需要进行优化，不能是O(n)
//             // 所以我们用哈希表进行存储，存储前缀和和下标的关系
//             // 如果后面的前缀和能够被找到，可以更新答案，但是不需要存储重复的，因为我们需要的是最大的范围
//             if (um.find(presum[i]) == um.end())
//                 um[presum[i]] = i;
//             else
//                 ret = std::max(ret, i - um[presum[i]]);
//         }

//         return ret;
//     }

// private:

//     int presum[N] = {0}; // 注意{1}的初始化只有第一个为1，其余为0
// };
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
