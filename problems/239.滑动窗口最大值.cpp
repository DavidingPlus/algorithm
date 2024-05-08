/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <deque>
#include <set>
#include <vector>

class Solution {
public:
    // 解法1：正统的滑动窗口
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 为了提升效率不让每次都寻找窗口里面的最大值，我们保证队列进来的数字一定是比队列头部小的，如果大的话就循环出队列直到新进来的值是最大的
        // 因为新进来的比旧的后出去，也就是说就算他们一起参与比较，肯定是新的胜出，并且旧的先出去，所以不用担心新的比他们先出去而考虑不全面的问题，因此我们可以放心弹出
        vector<int> res;
        deque<pair<int, int>> d;

        for (int i = 0; i < nums.size(); ++i) {
            // 前面的分析有一些疏漏的地方，就是队列新进来的数字一定必须是队列里面最小的，例如 3 1 ，进来2，这个1一样没有用处，所以我们从尾部开始判断，因此改用deque

            // 判断数量超出，不能简单的看d的个数，因为中间很可能有很多个因为值不对而没有进来，导致这个判断错误
            if (!d.empty() and (k == i - d.front().second))
                d.pop_front();

            // 然后再看大小关系
            while (!d.empty() and d.back().first <= nums[i])
                d.pop_back();

            d.emplace_back(nums[i], i);

            // 前几次的压入是不算最大值的
            if (i >= k - 1)
                res.push_back(d.front().first);
        }

        return res;
    }
};
// @lc code=end
