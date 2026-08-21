/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 我们把这个题转化一下
    // 分割数组变为运送货物，每天运送的个数不能超过这个最大值的最小值
    // 然后要在m天内运送完毕，这就是前面的问题，问题1011

    int f(vector<int>& weights, int load_weight) {
        int i = 0, days = 0, weight = 0;

        for (; i < weights.size(); ++i) {
            weight = 0;
            while (1) {
                weight += weights[i];
                // 判断装下一个是否会满
                if (i == weights.size() - 1 || weight + weights[i + 1] > load_weight)
                    break;
                ++i;
            }
            ++days;
        }

        return days;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 10;

        // 找出left和right，left就是数组的最大值，right就是所有包裹加起来的重量，为了防止边界我取大点
        for (auto val : nums) {
            left = max(left, val);
            right += val;
        }

        // 找左边界
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (k == f(nums, mid))
                right = mid;
            else if (f(nums, mid) > k)
                left = mid + 1;
            else if (f(nums, mid) < k)
                right = mid;
        }

        return left;
    }
};
// @lc code=end
