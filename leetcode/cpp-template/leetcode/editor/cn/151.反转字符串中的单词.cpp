/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    const std::string SEP = " ";


    std::string reverseWords(std::string s)
    {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string token;

        // getline 按 SEP[0] 切分字符串；如果分隔符连续出现（比如 "   "），或者出现在开头，就可能读取到空 token。token.empty() 只负责阻止它加入 words。
        while (std::getline(ss, token, SEP[0]))
        {
            if (!token.empty()) words.emplace_back(token);
        }

        std::string res;
        for (int i = words.size() - 1; i >= 0; --i)
        {
            res += words[i];
            if (0 != i) res += SEP;
        }


        return res;
    }

    // 旧版代码。
    // std::string reverseWords(std::string s)
    // {
    //     // 先切片再合并。
    //     // 切片利用状态机的思路，当遇到第一个非空的字符，进入字符状态，存储另一个指针往有遍历，知道遇到空字符或者越界结束。空字符就进入下一个循环，越界就计算结束。

    //     std::vector<std::string> words;

    //     int i = 0;
    //     while (1)
    //     {
    //         if (' ' != s[i])
    //         {
    //             int j = i;
    //             for (; ' ' != s[j] && j < s.size(); ++j)
    //                 ;

    //             words.push_back(s.substr(i, j - i));

    //             // 最后一个单词也要写入数组，因此跳出放在后面。
    //             if (j == s.size()) break;

    //             i = j;
    //         }
    //         else
    //         {
    //             ++i;

    //             if (i == s.size()) break;
    //         }
    //     }

    //     std::string res;
    //     for (int i = words.size() - 1; i >= 0; --i)
    //     {
    //         res += words[i];

    //         if (i) res += ' ';
    //     }


    //     return res;
    // }

    // TODO 如何在原地修改的情况下，即空间复杂度为 O(1) 下完成本题？
    // 核心是三步：
    // 1. 原地删除多余空格，保证单词之间只有一个空格。
    // 2. 原地反转整个字符串。
    // 3. 再原地反转每个单词。
    // std::string reverseWords(std::string s)
    // {
    // }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here

    std::cout << "\"" << solution.reverseWords("the sky is blue") << "\"" << std::endl;
    std::cout << "\"" << solution.reverseWords("  hello world  ") << "\"" << std::endl;
    std::cout << "\"" << solution.reverseWords("a good   example") << "\"" << std::endl;
}
