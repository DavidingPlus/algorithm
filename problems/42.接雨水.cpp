/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // 对于i来讲，该位置能够街道的雨水量取决于左右两边最高的柱子
        // 该位置的最高水量等于左右两边最高的柱子中的最小值减去该位置的值，当然一定要比他高才行

        // 这里是该位置左右两边的最大值，不是最近比他大的哈!
        // 找到任意位置左边的最大值，我从左边开始遍历，记录路程中遇到的最大值，然后记录每个位置的值即可

        int leftMax = 0, rightMax = 0;
        vector<int> leftMaxs(n), rightMaxs(n);
        for (int i = 0; i < n; ++i) {
            leftMaxs[i] = leftMax;
            leftMax = max(leftMax, height[i]);

            rightMaxs[n - 1 - i] = rightMax;
            rightMax = max(rightMax, height[n - 1 - i]);
        }

        // 遍历一次得出最后的值
        int res = 0;
        for (int i = 0; i < n; ++i)
            res += (min(leftMaxs[i], rightMaxs[i]) >= height[i]) ? min(leftMaxs[i], rightMaxs[i]) - height[i] : 0;

        return res;
    }
};
// @lc code=end
