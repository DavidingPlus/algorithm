/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

const int N = 1e3 + 10;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 各个站的人可以构成一个数组
        // 不同批次的顾客在某个站下，某个站上，因此某个区间站的人会进行修改，因此可以用到差分数组
        int dif[N] = {0};

        int max_station = 0;

        for (auto& trip : trips) {
            dif[trip[1]] += trip[0];
            dif[trip[2]] -= trip[0];  // 下车的时候这站的人数已经减少了，所以下了的人不参与进来
            max_station = max(max_station, trip[2]);
        }

        int num = 0;
        for (int i = 1; i <= max_station; ++i) {
            num += dif[i - 1];
            if (num > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end
