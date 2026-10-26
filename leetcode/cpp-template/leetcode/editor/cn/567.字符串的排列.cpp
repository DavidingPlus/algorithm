/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"


// @lc code=start

class Solution
{

public:

    bool checkInclusion(std::string s1, std::string s2)
    {
        std::unordered_map<char, int> um1, um2;

        for (auto &ch : s1) ++um1[ch];

        // 左闭右开的区间。
        int left = 0, right = 0, valid = 0;
        while (right < s2.size())
        {
            // 最直观是否匹配的方法是判断两个哈希表是否相等，但这样的开销很大，并且需要额外处理哈希表中元素为 0 时删除的额外开销（um1 = {a:1, b:1}，um2 = {a:1, b:1, c:0} 这是满足条件的但是这两个哈希表并不相等），因此换一种思路比较。
            // valid 表示窗口中出现次数恰好符合要求的字符种类数。窗口长度等于 s1.size() 时，若 valid == um1.size()，就说明所有目标字符都恰好匹配。字符进入或离开窗口时，都要处理计数进入和离开“刚好相等”状态的情况。

            // 这里不能用引用，因为不能修改原串本身。
            // 由于和 um1 比，因此只关心 um1 中出现的字符即可。
            char ch = s2[right++];
            if (um1.count(ch))
            {
                // 原本刚好，添加后超出。
                if (um1[ch] == um2[ch]) --valid;

                ++um2[ch];

                // 原本不足，添加后刚好。
                if (um1[ch] == um2[ch]) ++valid;
            }

            // right 一直往右移动，直到窗口大小等于 s1.size()，这时 left 往右移动一步，这时候窗口大小又小于 s1.size() 了，right 继续往右移动，进入下一次循环。这个设计兼顾了初始条件 right 往右移动以及后续的迭代。
            if (s1.size() == right - left)
            {
                if (um1.size() == valid) return true;

                ch = s2[left++];
                if (um1.count(ch))
                {
                    // 原本刚好，移出后不足。
                    if (um1[ch] == um2[ch]) --valid;

                    --um2[ch];

                    // 原本超量，移出后刚好。
                    if (um1[ch] == um2[ch]) ++valid;
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
