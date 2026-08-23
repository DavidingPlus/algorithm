/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start

class Solution
{

public:

    bool checkInclusion(std::string s1, std::string s2)
    {
        // 本题使用一个定长滑动窗口即可。为了优化复杂度，依旧使用 valid 变量。
        std::unordered_map<char, int> um1, um2;

        for (auto &c : s1) ++um1[c];

        // 定义左闭右开的区间。
        int left = 0, right = 0, valid = 0;

        while (right < s2.size())
        {
            // right 一直往右移动，直到窗口大小等于 s1.size()，这时 left 往右移动一步，这时候窗口大小又小于 s1.size() 了，right 继续往右移动，进入下一次循环。这个设计兼顾了初始条件 right 往右移动以及后续的迭代。

            char c = s2[right++];
            if (um1.count(c))
            {
                if (++um2[c] == um1[c]) ++valid;

                if (um1.size() == valid) return true;
            }

            if (s1.size() == right - left)
            {
                char d = s2[left++];
                if (um1.count(d))
                {
                    if (um2[d]-- == um1[d]) --valid;
                }
            }
        }

        return false;
    }


    // 旧版代码。
    // bool checkInclusion(std::string s1, std::string s2) {
    //     // 滑动窗口，首先s1的大小一定等于s2的大小，让s2的滑动窗口保持s1的长度，然后去判断两个是否满足条件即可
    //     if (s1.size() > s2.size())
    //         return false;

    //     std::unordered_map<char, int> um1;
    //     for (auto& ch : s1)
    //         ++um1[ch];  // 存在++，不存在会创建并且赋初值0，然后++

    //     std::unordered_map<char, int> um2;
    //     int left = 0, right = 0;  // 区间选定左闭右开

    //     // 先移动到区间长度相等的位置
    //     while (right - left < s1.size()) {
    //         ++um2[s2[right]];
    //         ++right;
    //     }

    //     // 做第一次判断
    //     if (um1 == um2)
    //         return true;

    //     while (right < s2.size()) {
    //         // 左边弹出
    //         if (1 == um2[s2[left]])
    //             // 这里删掉，因为不能让0存在，会影响相等判断
    //             um2.erase(s2[left]);
    //         else
    //             --um2[s2[left]];
    //         ++left;

    //         // 右边进入
    //         ++um2[s2[right]];
    //         ++right;

    //         // 这里做判断，防止最后一次的判断没包含，但是这样需要在前面再做一次判断
    //         if (um1 == um2)
    //             return true;
    //     }

    //     return false;
    // }
};
// @lc code=end


int main()
{
    Solution solution;

    std::string s1{"ab"}, s2{"eidbaooo"};

    std::cout << std::boolalpha << solution.checkInclusion(s1, s2) << std::endl;
}
