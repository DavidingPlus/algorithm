/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

const int N = 1e5 + 10;

class Solution {
public:
    bool isContain(const unordered_map<char, pair<int, int>>& um) {
        for (auto& each : um) {
            if (each.second.first < each.second.second)
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        string res;
        res.resize(N);

        // 滑动窗口的思想，本质其实还是双指针
        // 只是我们做了限制，让两个指针什么时候可以有序的右移
        // 思路：
        // 1.右指针右移，到达可以包含的位置，记录
        // 2.左指针右移，尽可能让这个滑动窗口尽量小，直到不满足条件，过程中记录
        // 3.右指针继续右移，重复上述工作
        // 4.直到右指针移到最右边并且左指针移到不满足条件的最左边

        // 这个算法的时间复杂度是O(n)，因为我们只遍历了一遍
        unordered_map<char, pair<int, int>> um;  // pair中第一个存储现在滑动窗口中的个数，第二个存储t字符串中对应的个数

        // 初始化um
        for (auto& ch : t) {
            if (0 == um.count(ch))  // count函数，查看key是否存在，存在返回1，不存在返回0
                um[ch] = {0, 1};
            else
                ++um[ch].second;
        }

        // 这里的滑动窗口，使用左闭右开，这样可以很好的避免边界条件
        int left = 0, right = 0;
        while (right <= s.size()) {
            // 右指针右移
            if (1 == um.count(s[right]))
                ++um[s[right]].first;
            ++right;

            if (!isContain(um))
                continue;

            // 判断是否满足条件
            while (1) {
                // 左指针左移直到直到不满足条件
                if (1 == um.count(s[left]))
                    --um[s[left]].first;
                ++left;

                if (!isContain(um))
                    break;
            }

            res = (res.size() < right - left + 1) ? res : s.substr(left - 1, right - left + 1);
        }

        // 如果没找到返回空串
        if (N == res.size())
            return string();
        return res;
    }
};
// @lc code=end
