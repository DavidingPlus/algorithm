/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <iostream>
using namespace std;
#include <vector>

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 两根指针，加起来的值小把左边的指针往右移，大了把右边的指针往左边移动
        // 为什么小了不把右边的往右移？（从初始状态考虑，这样相当于往回走了）
        // 我们的状态初始时候肯定有一个指针要单向移动，很可能在这个过程中一直状态不变
        // 当状态变化的时候不能回移，肯定就让另一根移动
        // 这样的遍历是从外层到内层，不会少的

        // 使用双指针
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (target == sum)
                return {1 + left, 1 + right};
            else if (sum > target)
                --right;
            else if (sum < target)
                ++left;
        }
        return {-1, -1};
    }
};
// @lc code=end
