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


    // std::string reverseWords(std::string s)
    // {
    //     std::vector<std::string> words;
    //     std::stringstream ss(s);
    //     std::string token;

    //     // getline 按 SEP[0] 切分字符串；如果分隔符连续出现（比如 "   "），或者出现在开头，就可能读取到空 token。token.empty() 只负责阻止它加入 words。
    //     while (std::getline(ss, token, SEP[0]))
    //     {
    //         if (!token.empty()) words.emplace_back(token);
    //     }

    //     std::string res;
    //     for (int i = words.size() - 1; i >= 0; --i)
    //     {
    //         res += words[i];
    //         if (0 != i) res += SEP;
    //     }


    //     return res;
    // }

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

    // 如何在原地修改的情况下，即空间复杂度为 O(1) 下完成本题？
    std::string reverseWords(std::string s)
    {
        // 1. 原地删除多余空格，保证单词之间只有一个空格。

        // 使用快慢指针的思路，快指针读到的有效字符往慢指针的位置填充。
        // fast 负责读取原字符串，slow 负责写入压缩后的字符串。
        // slow 不会超过 fast，因此写入不会覆盖尚未读取的字符。
        // 例如："  a good   example  " 会被压缩成 "a good example"。
        int fast = 0, slow = 0, newSize = 0;

        for (; fast < s.size(); ++fast)
        {
            // 正常填充字符。
            if (SEP[0] != s[fast])
            {
                s[slow++] = s[fast];
                // slow 指向下一个待写入位置，也就是当前有效内容的长度。
                newSize = slow;
            }
            // 遇到分割符。
            else
            {
                // 只有已经写入过内容，且上一个写入字符不是空格时，才补充一个空格。
                // 1. 0 != slow 代表不是头部的分隔符。
                // 2. 如果上一个位置（slow - 1）已经是分隔符了，不能继续填充重复字符。
                if (0 != slow && SEP[0] != s[slow - 1])
                {
                    // 填充分割符的情况下，newSize 需要将分隔符排除，因为可能后续全是分隔符，不能将尾部的分割符记录下来。如果后面是正常字符，newSize 会重新在前面更新。
                    newSize = slow;
                    s[slow++] = SEP[0];
                }
            }
        }

        // slow 后面的内容已经无效，通过 resize 删除。newSize 保证末尾空格不会被保留。
        s.resize(newSize);

        // 空字符串不能直接使用 s.size() - 1，因为 size() 是无符号类型，为空时会发生下溢。
        if (s.empty()) return s;

        // 2. 原地反转整个字符串。
        // 例如："a good example" -> "elpmaxe doog a"。
        reverseStrFromRange(s, 0, s.size() - 1);

        // 3. 再原地反转每个单词。
        // 整体反转后，每个单词内部的字符顺序也反了，因此再按照空格找到每个单词并单独反转。
        // 例如："elpmaxe doog a" -> "example good a"。
        int start = 0, offset = 0;
        while (true)
        {
            offset = s.find(SEP[0], start);
            // 找不到分隔符了，说明是最后的一段。
            if (std::string::npos == offset)
            {
                reverseStrFromRange(s, start, s.size() - 1);
                break;
            }
            // 正常翻转。
            else
            {
                reverseStrFromRange(s, start, offset - 1);
                start = 1 + offset;
            }
        }


        return s;
    }

    void reverseStrFromRange(std::string &s, int left, int right)
    {
        while (left < right) std::swap(s[left++], s[right--]);
    }
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
