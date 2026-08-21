/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // 题目读起很复杂，其实就是一个单调栈，存储右边第一个比他大于等于的元素，注意等于的情况下也会把后面遮蔽
        // TODO 这个题目有陷阱，例如样例的0号看不到3号，我靠...

        // vector<int> res(heights.size());
        // stack<int> s;
        // for (int i = heights.size() - 1; i >= 0; --i) {
        //     while (false == s.empty() && heights[i] > heights[s.top()]) s.pop();
        //     res[i] = s.empty() ? heights.size() - i - 1 : s.top() - i;
        //     s.push(i);
        // }
        // return res;
    }
};
// @lc code=end
