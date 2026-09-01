/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30404
 *
 * [14] 最长公共前缀
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string res;

        // res 的长度不会超过 strs 中的最短字符串，为了方便这里以第一个字符串的长度为基准。
        for (int j = 0; j < strs[0].size(); ++j)
        {
            char ch = strs[0][j];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i].size() == j || strs[i][j] != ch) return res;
            }
            res += ch;
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
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
