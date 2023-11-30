/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈，只不过这一次栈里面存入的是下标
        stack<pair<int, int>> s;
        vector<int> res;
        res.resize(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!s.empty() and temperatures[i] >= s.top().first)
                s.pop();

            res[i] = s.empty() ? 0 : s.top().second - i;

            s.push({temperatures[i], i});
        }

        return res;
    }
};
// @lc code=end
