/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty()) return 0;

        // 维护一个滑动窗口（左闭右开），初始 left = 0, right = 0。当 right 往右移动的过程中，如果出现重复字符，代表 right 往右的子串全部都不满足，此时应该移动 left，使得重复字符移出窗口。然后进行下一轮的循环。
        // 其实这等价于一个一维线性 DP 问题，使用 dp[i] 代表以 i 结尾的不含有重复字符的最长子串的长度。当下一个字符进来的时候，根据是否重复的逻辑去更新 dp[i + 1] 即可。

        std::string_view sv{s};
        int res = 1;
        // 滑动窗口在动态规划中的应用，dp[i] 代表以 i 字符结尾的最长不重复子串的长度。
        std::vector<int> dp(s.size());
        dp[0] = 1;

        for (int i = 1; i < s.size(); ++i)
        {
            // 在当前不含有重复字符的子串中查找新进来的字符，因为 dp 对应的子串我们从语义上保证不重复，因此查找结果只有一个唯一值。
            // 注意这个 pos 是相对子串的下标，不是整串 s。
            auto pos = sv.substr(i - dp[i - 1], dp[i - 1]).find(s[i]);

            if (std::string_view::npos == pos)
            {
                dp[i] = 1 + dp[i - 1];
            }
            else
            {
                dp[i] = i - (i - dp[i - 1] + pos);
            }

            res = std::max(res, dp[i]);
        }


        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here

    std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;
}
