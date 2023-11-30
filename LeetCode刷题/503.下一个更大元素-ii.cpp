/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 现在数组是循环的，因此每个元素理论上来说都可以绕一圈来寻找，所以为了模拟这个过程，可以把数组扩大2倍，当然不是真的扩大，只是用 % 来模拟了这个过程
        stack<int> s;
        vector<int> res;
        // res.resize(2 * nums.size());

        // for (int i = 2 * nums.size() - 1; i >= 0; --i) {
        //     // 比较，弹出
        //     while (!s.empty() and nums[i % nums.size()] >= s.top())
        //         s.pop();

        //     res[i] = s.empty() ? -1 : s.top();

        //     s.push(nums[i % nums.size()]);
        // }

        // res.resize(nums.size());
        // return res;

        // 我们做一个优化，这里的res其实只用开nums.size()就可以了，因为我去模，前面的数据就会被真正需要的答案给覆盖掉
        res.resize(nums.size());

        for (int i = 2 * nums.size() - 1; i >= 0; --i) {
            // 比较，弹出
            while (!s.empty() and nums[i % nums.size()] >= s.top())
                s.pop();

            res[i % nums.size()] = s.empty() ? -1 : s.top();

            s.push(nums[i % nums.size()]);
        }

        return res;
    }
};
// @lc code=end
