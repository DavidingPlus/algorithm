/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

const int N = 2 * 1e4 + 10;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 差分数组，将nums数组看作为前缀和数组，然后构造出原来的数组
        // 之后修改原来的数组，再求一次前缀和数组即可得到答案

        int df[N] = {0};  // 初始化差分数组
        for (auto& book : bookings) {
            int left = book[0], right = book[1], val = book[2];
            df[left - 1] += val;
            df[right] -= val;
        }

        // 构造前缀和数组
        vector<int> ret;
        ret.push_back(0);

        for (int i = 0; i < n; ++i)
            ret.push_back(ret.back() + df[i]);

        ret.erase(ret.begin());

        return ret;
    }
};
// @lc code=end
