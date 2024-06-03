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
        int n = nums.size();

        // 现在数组是循环的，因此每个元素理论上来说都可以绕一圈来寻找，所以为了模拟这个过程，可以把数组扩大2倍，当然不是真的扩大，只是用 % 来模拟了这个过程
        stack<int>
            s;
        vector<int> res;

        // res.resize(2 * n);
        // for (int i = 2 * n - 1; i >= 0; --i) {
        //     // 比较，弹出
        //     while (!s.empty() && nums[i % n] >= s.top())
        //         s.pop();

        //     res[i] = s.empty() ? -1 : s.top();

        //     s.push(nums[i % n]);
        // }

        // res.resize(n);
        // return res;

        // 我们做一个优化，这里的res其实只用开n就可以了，因为我去模，前面的数据就会被真正需要的答案给覆盖掉
        res.resize(n);

        for (int i = 2 * n - 1; i >= 0; --i) {
            // 比较，弹出
            while (false == s.empty() && nums[i % n] >= s.top())
                s.pop();

            res[i % n] = s.empty() ? -1 : s.top();

            s.push(nums[i % n]);
        }

        return res;
    }
};
// @lc code=end
