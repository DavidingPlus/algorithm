/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 我看能不能通过二分来筛选，这时候的筛选条件就是某处的元素值和临近元素的大小关系
        int left = 0, right = nums.size() - 1;  // 使用闭区间

        // 这里取等，让相等的时候终止，得到答案
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 相邻的值不同
            if (nums[mid] < nums[mid + 1])  // 小于，说明右边的值可能是峰值元素
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end
