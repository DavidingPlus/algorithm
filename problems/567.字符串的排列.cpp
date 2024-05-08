/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 滑动窗口，首先s1的大小一定等于s2的大小，让s2的滑动窗口保持s1的长度，然后去判断两个是否满足条件即可
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> um1;
        for (auto& ch : s1)
            ++um1[ch];  // 存在++，不存在会创建并且赋初值0，然后++

        unordered_map<char, int> um2;
        int left = 0, right = 0;  // 区间选定左闭右开

        // 先移动到区间长度相等的位置
        while (right - left < s1.size()) {
            ++um2[s2[right]];
            ++right;
        }

        // 做第一次判断
        if (um1 == um2)
            return true;

        while (right < s2.size()) {
            // 左边弹出
            if (1 == um2[s2[left]])
                // 这里删掉，因为不能让0存在，会影响相等判断
                um2.erase(s2[left]);
            else
                --um2[s2[left]];
            ++left;

            // 右边进入
            ++um2[s2[right]];
            ++right;

            // 这里做判断，防止最后一次的判断没包含，但是这样需要在前面再做一次判断
            if (um1 == um2)
                return true;
        }

        return false;
    }
};
// @lc code=end
