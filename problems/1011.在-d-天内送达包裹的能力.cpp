/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 这个问题的自变量是船的称重，因变量是运送的时间，并且是单调不增的函数
    // 由于必须按照给定的顺序进行装运，因此可以线性的描绘这个函数
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

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 10;

        // 找出left和right，left就是数组的最大值，right就是所有包裹加起来的重量，为了防止边界我取大点
        for (auto val : weights) {
            left = max(left, val);
            right += val;
        }

        // 找左边界
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (days == f(weights, mid))
                right = mid;
            else if (f(weights, mid) > days)
                left = mid + 1;
            else if (f(weights, mid) < days)
                right = mid;
        }

        return left;
    }
};
// @lc code=end
