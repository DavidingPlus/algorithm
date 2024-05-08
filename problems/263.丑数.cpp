/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return false;

        // 判断这个数是否包含2,3,5的因子，如果包含就除以这个因子直到变为1
        while (0 == n % 2) n = n / 2;
        while (0 == n % 3) n = n / 3;
        while (0 == n % 5) n = n / 5;

        return 1 == n;
    }
};
// @lc code=end
