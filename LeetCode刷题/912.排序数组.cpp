/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 方法1：归并排序
    vector<int> sortArray(vector<int>& nums) {
        tmp = nums;

        // 先左右递归排序，再合并
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        // 左右递归排序，闭区间
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        // merge
        merge(nums, left, right, mid);
    }

    vector<int> tmp;  // merge时需要的辅助数组

    void merge(vector<int>& nums, int left, int right, int mid) {
        // 左边的范围是[left , mid]
        // 右边的范围是[mid + 1 , right]

        // 将原数组对应的位置拷贝一份
        for (int i = left; i <= right; ++i)
            tmp[i] = nums[i];

        // 双指针
        int pl = left, pr = mid + 1;

        for (int i = left; i <= right; ++i) {
            if (pl > mid)  // 左边完毕了
                nums[i] = tmp[pr++];
            else if (pr > right)  // 右边完毕了
                nums[i] = tmp[pl++];
            // 比较大小
            else if (tmp[pl] <= tmp[pr])
                nums[i] = tmp[pl++];
            else
                nums[i] = tmp[pr++];
        }
    }
};
// @lc code=end
