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
        stack<int> s;
        vector<int> res(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (false == s.empty() && temperatures[i] >= temperatures[s.top()])
                s.pop();

            res[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return res;
    }
};
// @lc code=end
