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
    void swap(char& ch1, char& ch2) {
        char tmp = ch1;
        ch1 = ch2;
        ch2 = tmp;
    }

    void reverseString(vector<char>& s) {
        // 两根指针，从两边到中间
        int left = 0, right = s.size() - 1;
        while (left < right)
            swap(s[left++], s[right--]);
    }
};
// @lc code=end
