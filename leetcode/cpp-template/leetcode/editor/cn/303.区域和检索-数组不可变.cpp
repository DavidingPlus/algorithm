/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e4 + 10;

class NumArray {
private:
    // 前缀和数组一般是用来区域快速求和的
    int preSum[N] = {0};

public:
    NumArray(vector<int>& nums) {
        // 前缀和数组为了避免边界条件，下标从1开始
        for (int i = 1; i <= nums.size(); ++i)
            preSum[i] = preSum[i - 1] + nums[i - 1];
    }

    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated && called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
