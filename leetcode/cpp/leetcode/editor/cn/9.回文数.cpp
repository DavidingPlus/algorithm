/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start


class Solution {
public:
    bool isPalindromeString(const std::string& str) {
        // 滑动窗口左右扩张
        int right = str.size() / 2;
        int left = (str.size() & 1) ? right : right - 1;

        while (left >= 0) {
            if (str[left] != str[right])
                return false;
            --left, ++right;
        }
        return true;
    }

    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        return isPalindromeString(std::to_string(x));
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
