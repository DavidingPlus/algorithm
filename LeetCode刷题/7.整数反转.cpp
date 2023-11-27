/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    // 方法1：通过字符串
    int reverse(int x) {
        string str = to_string(abs(x));

        str = string(str.rbegin(), str.rend());

        int res = 0;

        try {
            res = stoi(str);
        } catch (...) {
            return 0;
        }

        return x > 0 ? res : -res;
    }
};
// @lc code=end
