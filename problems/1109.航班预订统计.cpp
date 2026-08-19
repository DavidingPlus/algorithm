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
        // 想对数组进行某个区间的修改，就可以用到差分数组(就是前缀和数组逆向的原数组)
        int dif[N] = {0};

        // 构造差分数组
        for (auto& book : bookings) {
            dif[book[0] - 1] += book[2];
            if (n != book[1])
                dif[book[1]] -= book[2];
        }

        // 反过来推导前缀和数组
        vector<int> ret{0};
        for (int i = 1; i <= n; ++i) {
            ret.push_back(ret.back() + dif[i - 1]);
        }
        ret.erase(ret.begin());

        return ret;
    }
};
// @lc code=end
