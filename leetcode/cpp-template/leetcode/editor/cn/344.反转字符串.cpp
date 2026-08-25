/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start




class Solution
{

public:

    void reverseString(std::vector<char> &s)
    {
        // 双指针的思想即可。
        for (int left = 0, right = s.size() - 1; left < right; ++left, --right) std::swap(s[left], s[right]);
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
