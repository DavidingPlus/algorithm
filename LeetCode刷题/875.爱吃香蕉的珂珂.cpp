/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 如何抽象为二分查找问题
    // 一个自变量：这个题中就是最小速度
    // 一个因变量：这个题中就是吃掉香蕉的时间，显然是一个单调递减的函数
    // 目标值：f(x)==h，我们要查询最小的速度k

    int times(vector<int>& piles, int k) {
        int hours = 0;

        for (auto& pile : piles) {
            hours += pile / k;
            if (pile % k > 0)
                ++hours;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 确定速度的最小值和最大值
        int left = 1, right = 1e9 + 10;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (h == times(piles, mid))
                right = mid;
            else if (times(piles, mid) > h)
                left = mid + 1;
            else if (times(piles, mid) < h)
                right = mid;
        }
        return left;
    }
};
// @lc code=end
