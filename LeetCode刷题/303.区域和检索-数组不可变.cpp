/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class NumArray {
public:
    NumArray(vector<int>& nums) {
        pre_sum[0] = 0;
        // 初始化前缀和数组，这里我的起始下标为1
        for (int i = 0; i < nums.size(); ++i)
            pre_sum[i + 1] = pre_sum[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }

private:
    int pre_sum[10010];  // 构造前缀和数组
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
