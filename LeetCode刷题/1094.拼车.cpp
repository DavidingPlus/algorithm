/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e3 + 1;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 定义差分数组
        int df[N] = {0};  // 最多1001个站
        for (auto& trip : trips) {
            int val = trip[0], left = trip[1], right = trip[2];
            df[left] += val;
            df[right] -= val;
        }

        // 构造前缀和数组，如果过程中一致保持小于容量则成功
        int presum[N + 1] = {0};
        for (int i = 1; i <= 1001; ++i) {
            presum[i] = presum[i - 1] + df[i - 1];
            if (presum[i] > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end
