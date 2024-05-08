/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // TODO
    // 有一些细节需要推敲
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 我们先找左侧边界，就是小于等于目标值的最大元素
        // 然后再用双指针往两边扩充，每次扩充都需要判断是不是合适的

        // 二分搜索找到 x 的位置
        int p = left_bound(arr, x);
        // 两端都开的区间 (left, right)
        int left = p - 1, right = p;
        vector<int> res;
        // 扩展区间，直到区间内包含 k 个元素
        while (right - left - 1 < k) {
            if (left == -1) {
                res.push_back(arr[right]);
                right++;
            } else if (right == arr.size()) {
                res.insert(res.begin(), arr[left]);
                left--;
            } else if (x - arr[left] > arr[right] - x) {
                res.push_back(arr[right]);
                right++;
            } else {
                res.insert(res.begin(), arr[left]);
                left--;
            }
        }
        return res;
    }

    // 这个二分是查找左边界
    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return left;
    }
};
// @lc code=end
