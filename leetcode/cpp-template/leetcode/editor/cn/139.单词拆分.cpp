/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30404
 *
 * [139] 单词拆分
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        // -1 代表没算过，0 代表失败，1 代表成功。
        memo.resize(1 + s.size(), -1);
        memo[0] = true;

        return dp(s, wordDict);
    }

    bool dp(std::string_view sv, const std::vector<std::string> &wordDict)
    {
        if (-1 != memo[sv.size()]) return memo[sv.size()];

        // 对给定的字符串，如果能由多个单词拼出，那么其中某个单词一定是他的前缀，因此我们先找出前缀，再递归剩余字符串。
        for (std::string_view word : wordDict)
        {
            // 先判断是否匹配前缀。
            if (sv.substr(0, word.size()) == word)
            {
                // 再递归调用 dp 函数即可。
                auto subStr = sv.substr(word.size());
                if (dp(subStr, wordDict))
                {
                    memo[sv.size()] = true;
                    return true;
                }
            }
        }


        memo[sv.size()] = false;
        return false;
    }


    // XXX 由于我们使用的是 std::string_view，通过 sv.size() 就能知道当前的遍历位置，进而作为 key 存储到 memo 中。当然对应 sv.size() 的语义，key 是当前字符串遍历剩余的长度，范围是 [0, s.size()]，因此 memo[0] == true。
    // 最开始犯了和 322 题零钱兑换一样的错误，注意一共有三个状态，没算过、失败和成功，如果存储 bool，就把没算过和失败混为一谈了，这样会导致失败的情况无法使用 memo，最后超时。
    std::vector<int> memo;
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// "leetcode"\n["leet","code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple","pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats","dog","sand","and","cat"]\n
// @lcpr case=end

 */
