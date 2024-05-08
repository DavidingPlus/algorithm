/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <iostream>
using namespace std;
#include <vector>

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right)
            std::swap(s[left++], s[right--]);
    }
};
// @lc code=end
