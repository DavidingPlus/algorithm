/*
 * @lc app=leetcode.cn id=424 lang=cpp
 * @lcpr version=30404
 *
 * [424] 替换后的最长重复字符
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int characterReplacement(std::string s, int k)
    {
        // 滑动窗口。我们考虑一个现成的滑动窗口，范围是 [left, right)，如果想要将其中的所有字符全部变成全部一样的，最小的次数是找到其中出现次数最多的字符，假设是 maxWindowCount 次，那么需要的次数就是 right - left - maxWindowCount 次。如果这个值 <= k，代表滑动窗口还可以扩张，++right，反之需要缩小滑动窗口。（考虑 == k 的特殊情况，这时应该 ++right，因为下一个值可能就是出现次数最多的字符，也满足条件，不满足条件再缩短窗口即可）

        std::unordered_map<char, int> windowCharCount;
        int maxWindowCount = 0, res = 0;

        int left = 0, right = 0;
        while (right < s.size())
        {
            int count = ++windowCharCount[s[right++]];
            maxWindowCount = std::max(maxWindowCount, count);

            // TODO 按道理来说，maxWindowCount 需要动态更新，但是这里为什么不需要呢？
            while (right - left - maxWindowCount > k)
            {
                --windowCharCount[s[left++]];
            }

            res = std::max(res, right - left);
        }


        return res;
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
// "ABAB"\n2\n
// @lcpr case=end

// @lcpr case=start
// "AABABBA"\n1\n
// @lcpr case=end

 */
