/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

const int N = 1e5 + 10;

class Solution {
public:
    // 常规解法，O(n^2)的动态规划
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 先对宽度进行排序，按照从小到大的顺序，然后这样宽度这边就ok了，然后高度这边就查找最长递增子序列(不一定连续)即可，和上一个题一样的思路
        // 但是这样会遇到一个问题，就是宽度相同高度应该怎么处理；从最直观的思路来讲，无非就是递增和递减，如果是递增的话，那么高度递增，如果高度低的选中了，那么更高的高度是一定可以选中的，意思是宽度相同的被选进来了，这显然是不符合条件的，所以这样一分析发现最好是递减；并且由于相同宽度只能选中一个，所以高度递减的话能保证前面选中了后面的就一定不会被选中，这样才能保证是这个问题的解

        // 排序
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& elem1, const vector<int>& elem2) {
            if (elem1[0] != elem2[0])
                return elem1[0] < elem2[0];
            else
                return elem1[1] > elem2[1];
        });

        // 求关于高度的最长递增子序列
        int dp[N] = {0};
        dp[0] = 1;

        int res = 1;

        for (int i = 1; i < envelopes.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);

            res = max(res, dp[i]);
        }
        return res;
    }

    // // 解法2：labuladong的二分的思路...
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n = envelopes.size();
    //     // 按宽度升序排列，如果宽度一样，则按高度降序排列
    //     sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
    //         if (a[0] == b[0]) {
    //             return b[1] < a[1];
    //         } else {
    //             return a[0] < b[0];
    //         }
    //     });
    //     // 对高度数组寻找 LIS
    //     vector<int> height(n);
    //     for (int i = 0; i < n; i++) {
    //         height[i] = envelopes[i][1];
    //     }
    //     return lengthOfLIS(height);
    // }

    // /* 返回 nums 中 LIS 的长度 */
    // int lengthOfLIS(vector<int>& nums) {
    //     int piles = 0, n = nums.size();
    //     vector<int> top(n);
    //     for (int i = 0; i < n; i++) {
    //         // 要处理的扑克牌
    //         int poker = nums[i];
    //         int left = 0, right = piles;
    //         // 二分查找插入位置
    //         while (left < right) {
    //             int mid = (left + right) / 2;
    //             if (top[mid] >= poker)
    //                 right = mid;
    //             else
    //                 left = mid + 1;
    //         }
    //         if (left == piles)
    //             piles++;
    //         // 把这张牌放到牌堆顶
    //         top[left] = poker;
    //     }
    //     // 牌堆数就是 LIS 长度
    //     return piles;
    // }
};
// @lc code=end
