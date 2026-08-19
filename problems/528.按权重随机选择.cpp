/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    vector<int> preSum{0};

    int binarySearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == nums[mid])
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        return right;
    }

public:
    Solution(vector<int>& w) {
        for (int i = 1; i <= w.size(); ++i)
            preSum.push_back(w[i - 1] + preSum[i - 1]);
    }

    int pickIndex() {
        // 从0开始，将每个下标的权重当作一条有长度的线段，然后长度越长概率越大，每个下标的起点位置就是上一个的终点位置，终点位置加上自身的权重，显然可以用前缀和数组存储所有的起点和终点信息
        // 整个随机数的范围是[0,最后一个位置)
        // 为了规范，我们规定左边界闭，有边界开，下面的随机数的生成就符合这个要求

        // 生成随机数
        int num = rand() % preSum.back();

        // 下面需要查找这个数处在的位置了
        // 我们需要用二分查找小于等于这个数的最大下标，和右边界对应...
        // 相对应的，大于等于这个数的最小下标，和左边界是对应的...
        return binarySearch(preSum, num);
    }
};

/**
 * Your Solution object will be instantiated && called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
