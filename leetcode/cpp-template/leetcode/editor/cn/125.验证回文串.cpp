/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30404
 *
 * [125] 验证回文串
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    bool isPalindrome(std::string s)
    {
        // std::isalnum(c); // 是否是字母或数字。
        // std::isalpha(c); // 是否是字母。
        // std::tolower(c); // 转小写。
        // std::toupper(c); // 转大写。

        // 这题能在 s 上原地完成，左右指针移动过程中，遇到非法字符跳过即可。
        int left = 0, right = s.size();
        while (left < right)
        {
            // 题目要求可以出现字母和数字字符。
            if (!isalnum(s[left]))
            {
                ++left;
                continue;
            }
            if (!isalnum(s[right]))
            {
                --right;
                continue;
            }

            if (tolower(s[left++]) != tolower(s[right--])) return false;
        }


        return true;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

// @lcpr case=start
// "121"\n
// @lcpr case=end

 */
