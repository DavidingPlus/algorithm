/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

const int N = 1e5 + 10;

class Solution {
public:
    int ret = 0;

    unordered_map<int, int> um;  // 存储前缀和和最小下标的哈希表

    int findMaxLength(vector<int>& nums) {
        // 对这个问题进行一个转换，就是0和1数量相同
        // 意思就是如果我把0替换为-1，这个连续子序列的和就为0，这就涉及到前缀和数组了

        // 填充前缀和数组
        // 注意在过程中将所有的0替换为-1
        for (int i = 1; i <= nums.size(); ++i)
            presum[i] = presum[i - 1] + ((0 == nums[i - 1]) ? -1 : 1);

        // 现在我再从头开始，每次加入一个新的数就多出了前面的数到这个数的序列和，我们遍历找出最大的即可
        for (int i = 0; i <= nums.size(); ++i) {
            // 这个地方的查询需要进行优化，不能是O(n)
            // 所以我们用哈希表进行存储，存储前缀和和下标的关系
            // 如果后面的前缀和能够被找到，可以更新答案，但是不需要存储重复的，因为我们需要的是最大的范围
            if (um.find(presum[i]) == um.end())
                um[presum[i]] = i;
            else
                ret = max(ret, i - um[presum[i]]);
        }

        return ret;
    }

private:
    int presum[N] = {0};  // 注意{1}的初始化只有第一个为1，其余为0
};
// @lc code=end
