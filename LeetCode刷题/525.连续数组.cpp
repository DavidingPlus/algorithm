/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e5 + 10;

class Solution {
public:
    int ret = 0;

    int findMaxLength(vector<int>& nums) {
        // 对这个问题进行一个转换，就是0和1数量相同
        // 意思就是如果我把0替换为-1，这个连续子序列的和就为0，这就涉及到前缀和数组了

        // 将所有的0替换为-1
        for (auto& val : nums)
            if (0 == val)
                val = -1;

        // 填充前缀和数组
        for (int i = 1; i <= nums.size(); ++i)
            presum[i] = presum[i - 1] + nums[i - 1];

        // 现在我再从头开始，每次加入一个新的数就多出了前面的数到这个数的序列和，我们遍历找出最大的即可
        // 超时
        // TODO
        for (int i = 1; i <= nums.size(); ++i)
            for (int j = 1; j < i; ++j) {
                if (0 == presum[i] - presum[j - 1])
                    ret = max(ret, i - j + 1);
            }

        return ret;
    }

private:
    int presum[N] = {0};  // 注意{1}的初始化只有第一个为1，其余为0
};
// @lc code=end
