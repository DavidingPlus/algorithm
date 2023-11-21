/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <cmath>
#include <string>

// 找一个比较大的素数作为去模的除数
const int Q = 1658598167;
// 进制
const int base = 27;

class Solution {
public:
    bool check(const string& haystack, const string& needle, int left) {
        string subStr = haystack.substr(left, needle.size());
        return subStr == needle;
    }

    int letterToInt(char ch) {
        return ch - 'a' + 1;
    }

    // 整个代码注意需要注意int越界和哈希冲突!!!
    int strStr(string haystack, string needle) {
        // 这个题用Rabin-Karp算法来做
        // 思路就是把字符串映射为数字，相当于求哈希值
        // 为了避免哈希值太大，要取模
        // 哈希冲突：遇到的时候就看当前的位置是否为答案，这时的暴力匹配时间不算什么
        // 整体框架采用滑动窗口实现

        if (haystack.size() < needle.size())
            return -1;

        // 关于字符串映射数字，由于仅由小写字母组成，可映射为1-26(不要0，放在首位怕出事)
        // 哈希算法就是按照27进制来，将这几个字母视作27进制的数
        // 当然如果是其他字符的话，可以考虑ASCII码的256进制
        // 在下面全部用base代替

        long long hashCode = 0;
        long long patCode = 0;
        for (int i = 0; i < needle.size(); ++i) {
            hashCode = (base * hashCode) % Q + letterToInt(haystack[i]) % Q;
            patCode = (base * patCode) % Q + letterToInt(needle[i]) % Q;
        }

        // 检测第一个
        if (hashCode == patCode and check(haystack, needle, 0))
            return 0;

        // 开始匹配
        long long upVal = 1;
        for (int i = 1; i < needle.size(); i++)
            // 计算过程中不断求模，避免溢出
            upVal = (upVal * base) % Q;  // 不能直接用pow()函数，因为过程中可能越界...

        for (int right = needle.size(); right < haystack.size(); ++right) {
            // 由于hashCode是去模出来的，所以这里很可能为负数，加上一个Q可以避免这个问题，让结果正确
            hashCode = (hashCode - (letterToInt(haystack[right - needle.size()]) * upVal) % Q + Q) % Q;
            hashCode = (base * hashCode) % Q + letterToInt(haystack[right]) % Q;

            if (hashCode == patCode and check(haystack, needle, right - needle.size() + 1))
                return right - needle.size() + 1;
        }
        return -1;
    }
};
// @lc code=end
