/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e4 + 10;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 先填充前缀和数组
        for (int i = 1; i <= nums.size(); ++i)
            presum[i] = presum[i - 1] + nums[i - 1];

        // 从左到右进行判断
        for (int i = 1; i <= nums.size(); ++i)
            if (presum[i - 1] - presum[0] == presum[nums.size()] - presum[i])
                return i - 1;

        return -1;
    }

private:
    int presum[N] = {0};
};
// @lc code=end
