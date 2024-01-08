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
        // 设置dp[i]的含义是以i下标结尾的最长递增子序列
        // 从i-1推导i，就是看0到i-1的每个子序列加上i的元素之后能否满足递增，然后合起来进行比较即可，因为i结尾的子序列去掉最后一个仍然是递增子序列，并且由于是最大所以肯定是倒数第二个下标对应的最大的

        int dp[N] = {0}, res = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end
