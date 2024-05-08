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

    int f(const vector<int>& piles, long long k) {
        int res = 0;
        for (int i = 0; i < piles.size(); i++) {
            res += piles[i] / k;
            if (piles[i] % k > 0)
                ++res;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 一个速度对应一个时间，时间是速度的递减函数，可以二分
        // 需要找到就是小于等于目标值的最大下标

        // 这个题目的左右边界不清晰，所以我们最好使用左闭右开，模糊一点，因为闭区间有组数据过不了(我也不知道为什么)
        int left = 1, right = 1e9 + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (h == f(piles, mid))
                right = mid;
            else if (f(piles, mid) > h)
                left = mid + 1;
            else if (f(piles, mid) < h)
                right = mid;
        }
        return left;
    }
};
// @lc code=end
