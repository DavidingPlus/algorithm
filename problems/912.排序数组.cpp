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
    /****************** 方法：快速排序 ******************/
    // 测试数据有狗啊，全放2。。。
    vector<int> sortArray(vector<int>& nums) {
        shuffle(nums);

        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        // 画图分析partition的工作流程就清楚了
        // 我取闭区间，最后用的是right交换

        if (left >= right)
            return;

        int p = patition(nums, left, right);
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }

    // 注意这个函数的细节，否则会死循环的...
    int patition(vector<int>& nums, int left, int right) {
        int guard = nums[left];

        int i = left + 1, j = right;
        while (i <= j) {
            // 先移动左边
            while (i < right && nums[i] <= guard)
                ++i;
            // 在移动右边
            while (j > left && nums[j] > guard)
                --j;

            if (i >= j)
                break;

            // 交换
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);

        return j;
    }

    // 洗牌算法，为了让partition的位置合理，需要随机打乱数组
    void shuffle(vector<int>& nums) {
        srand((unsigned)time(NULL));
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 生成 [i, n - 1] 的随机数
            int r = i + rand() % (n - i);
            swap(nums[i], nums[r]);
        }
    }

    /****************** 方法：归并排序 ******************/
    // vector<int> sortArray(vector<int>& nums) {
    //     tmp = nums;

    //     // 先左右递归排序，再合并
    //     mergeSort(nums, 0, nums.size() - 1);

    //     return nums;
    // }

    // void mergeSort(vector<int>& nums, int left, int right) {
    //     if (left >= right)
    //         return;

    //     int mid = left + (right - left) / 2;

    //     // 左右递归排序，闭区间
    //     mergeSort(nums, left, mid);
    //     mergeSort(nums, mid + 1, right);
    //     // merge
    //     merge(nums, left, right, mid);
    // }

    // vector<int> tmp;  // merge时需要的辅助数组

    // void merge(vector<int>& nums, int left, int right, int mid) {
    //     // 左边的范围是[left , mid]
    //     // 右边的范围是[mid + 1 , right]

    //     // 将原数组对应的位置拷贝一份
    //     for (int i = left; i <= right; ++i)
    //         tmp[i] = nums[i];

    //     // 双指针
    //     int pl = left, pr = mid + 1;

    //     for (int i = left; i <= right; ++i) {
    //         if (pl > mid)  // 左边完毕了
    //             nums[i] = tmp[pr++];
    //         else if (pr > right)  // 右边完毕了
    //             nums[i] = tmp[pl++];
    //         // 比较大小
    //         else if (tmp[pl] <= tmp[pr])
    //             nums[i] = tmp[pl++];
    //         else
    //             nums[i] = tmp[pr++];
    //     }
    // }
};
// @lc code=end
