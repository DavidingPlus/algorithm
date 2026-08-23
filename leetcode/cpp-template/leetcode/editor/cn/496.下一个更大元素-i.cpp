/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start


class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        // 先处理nums2的，用单调栈去处理，然后再根据nums1去做映射就好了
        // 单调栈，从后往前，每次进入的时候判断本值与栈中元素的大小，维持栈的单调性，在本题中我们需要找到最近的更大的元素，因此如果我想要进入的元素更大，那么后面的元素一定不是答案，出栈
        std::stack<int> s;
        std::vector<int> v(nums2.size());  // 存储num2的每个值
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (false == s.empty() && s.top() <= nums2[i])
                s.pop();

            v[i] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        // 做映射
        std::vector<int> res;
        for (auto& val : nums1)
            res.push_back(v[find(nums2.begin(), nums2.end(), val) - nums2.begin()]);
        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
