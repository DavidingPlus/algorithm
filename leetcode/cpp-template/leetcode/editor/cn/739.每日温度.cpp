/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        // 单调栈，只不过这一次栈里面存入的是下标
        std::stack<int> s;
        std::vector<int> res(temperatures.size());

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


int main()
{
    Solution solution;
    // your test code here
}
