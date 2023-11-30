/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 先处理nums2的，用单调栈去处理，然后再根据nums1去做映射就好了

        vector<int> array2;
        array2.resize(nums2.size());

        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() and nums2[i] >= s.top())
                s.pop();

            array2[i] = s.empty() ? -1 : s.top();

            s.push(nums2[i]);
        }

        vector<int> res;
        for (auto& val : nums1)
            res.push_back(array2[find(nums2.begin(), nums2.end(), val) - nums2.begin()]);

        return res;
    }
};
// @lc code=end
