/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 2500 + 10;

class Solution {
public:
    // 这个子序列不一定是连续的！
    int lengthOfLIS(vector<int>& nums) {
        // 定义dp数组为以i元素结尾的最长严格递增子序列的长度
        vector<int> dp;
        dp.resize(nums.size());
        fill(dp.begin(), dp.end(), 1);  // 需要全部初始化为1，因为不满足条件就表明为1
        int ret = dp[0];

        for (int i = 1; i < nums.size(); ++i) {
            // 现在的问题是如何已知dp[0]到dp[i-1]如何求出dp[i]
            // 一个递增子序列除去最后一个肯定也是递增子序列
            // 并且在本题中一定是以这个元素为结尾的递增子序列，否则就能找出更大的长度了
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);

            ret = max(ret, dp[i]);
        }

        return ret;
    }
};
// @lc code=end
