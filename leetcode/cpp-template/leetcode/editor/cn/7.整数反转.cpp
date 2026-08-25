/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution {
public:
    // 方法1：通过字符串
    int reverse(int x) {
        std::string str = std::to_string(std::abs(x));

        str = std::string(str.rbegin(), str.rend());

        int res = 0;

        try {
            res = std::stoi(str);
        } catch (...) {
            return 0;
        }

        return x > 0 ? res : -res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
