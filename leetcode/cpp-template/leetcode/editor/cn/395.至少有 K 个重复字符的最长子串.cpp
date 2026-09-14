/*
 * @lc app=leetcode.cn id=395 lang=cpp
 * @lcpr version=30404
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int longestSubstring(std::string s, int k)
    {
        // XXX 算法网站提供的思路。自己第一遍是真的想不到。

        /*
            在本题的场景中，我们想尽可能多地装字符，即扩大窗口，但不知道什么时候应该开始收缩窗口。

            为什么呢？比如窗口中有些字符出现次数不满足 k，但有可能再扩大扩大窗口就能满足 k 了呀？但要这么说的话，你干脆一直扩大窗口算了，所以你说不准啥时候应该收缩窗口。

            理论上讲，这种情况就不能用滑动窗口模板了，但有时候我们可以自己添加一些约束，来进行窗口的收缩。

            题目说让我们求每个字符都出现至少 k 次的子串，我们可以再添加一个约束条件：求每个字符都出现至少 k 次，仅包含 count 种不同字符的最长子串。

            添加了字符种类的限制，我们就可以回答滑动窗口算法的三个灵魂问题了：

            1、什么时候应该扩大窗口？窗口中字符种类小于 count 时扩大窗口。

            2、什么时候应该缩小窗口？窗口中字符种类大于 count 时缩小窗口。

            3、什么时候得到一个合法的答案？窗口中所有字符出现的次数都大于等于 k 时，得到一个合法的子串。

            然后就可以套用滑动窗口算法模板实现 logestKLetterSubstr 函数了。

            当然，题目没有 count 的约束，那没关系呀，count 能有几种取值？因为 s 中只包含小写字母，所以 count 的取值也就是 1~26，所以最后用一个 for 循环把这些值都输入 logestKLetterSubstr 计算一遍，求最大值就是题目想要的答案了。
        */

        int res = 0;
        for (int i = 1; i <= 26; ++i) res = std::max(res, logestKLetterSubstr(s, k, i));
        return res;
    }

    // 在 s 中寻找仅含有 count 种字符，且每种字符出现次数都大于 k 的最长子串。
    int logestKLetterSubstr(std::string s, int k, int count)
    {
        int res = 0;

        // 因为只有 26 个字符，用数组代替哈希表。
        int windowCount[26] = {0};

        // 滑动窗口中存在多少种不同的字符。
        int windowUniqueCount = 0;

        // 滑动窗口中存在多少种达标的字符。
        int windowValidCount = 0;

        int left = 0, right = 0;

        while (right < s.size())
        {
            int idx = s[right] - 'a';

            // 这里应该判断 idx 第一次出现，不能放在 ++windowCount[idx] 语句后面使用 > 0 的条件，这样会导致来一次加一次，放在后面应使用 == 1 条件。
            if (0 == windowCount[idx]) ++windowUniqueCount;

            ++windowCount[idx];

            // 同上，这里也只在刚好到达 k 时增加。
            if (k == windowCount[idx]) ++windowValidCount;

            ++right;

            while (left < right && windowUniqueCount > count)
            {
                idx = s[left] - 'a';

                // 同上，这里也只在刚好跌落 k 时减少。
                if (k == windowCount[idx]) --windowValidCount;

                --windowCount[idx];

                if (0 == windowCount[idx]) --windowUniqueCount;

                ++left;
            }

            if (windowUniqueCount == windowValidCount) res = std::max(res, right - left);
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
// "aaabb"\n3\n
// @lcpr case=end

// @lcpr case=start
// "ababbc"\n2\n
// @lcpr case=end

 */
