/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start




class Solution
{

public:

    /****************** 方法：快速排序 ******************/
    // // 测试数据有狗啊，全放2。。。
    // std::vector<int> sortArray(std::vector<int> &nums)
    // {
    //     shuffle(nums);

    //     quickSort(nums, 0, nums.size() - 1);
    //     return nums;
    // }

    // void quickSort(std::vector<int> &nums, int left, int right)
    // {
    //     // 画图分析partition的工作流程就清楚了
    //     // 我取闭区间，最后用的是right交换

    //     if (left >= right)
    //         return;

    //     int p = patition(nums, left, right);
    //     quickSort(nums, left, p - 1);
    //     quickSort(nums, p + 1, right);
    // }

    // // 注意这个函数的细节，否则会死循环的...
    // int patition(std::vector<int> &nums, int left, int right)
    // {
    //     int guard = nums[left];

    //     int i = left + 1, j = right;
    //     while (i <= j)
    //     {
    //         // 先移动左边
    //         while (i < right && nums[i] <= guard)
    //             ++i;
    //         // 在移动右边
    //         while (j > left && nums[j] > guard)
    //             --j;

    //         if (i >= j)
    //             break;

    //         // 交换
    //         std::swap(nums[i], nums[j]);
    //     }
    //     std::swap(nums[left], nums[j]);

    //     return j;
    // }

    // // 洗牌算法，为了让partition的位置合理，需要随机打乱数组
    // void shuffle(std::vector<int> &nums)
    // {
    //     srand((unsigned)time(NULL));
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         // 生成 [i, n - 1] 的随机数
    //         int r = i + rand() % (n - i);
    //         std::swap(nums[i], nums[r]);
    //     }
    // }


    /****************** 方法：归并排序 ******************/
    std::vector<int> sortArray(std::vector<int> &nums)
    {
        backup.resize(nums.size());

        mergeSort(nums, 0, nums.size() - 1);


        return nums;
    }

    std::vector<int> backup;

    void mergeSort(std::vector<int> &nums, int left, int right)
    {
        // 递归出口必须是 >= 而不是 >，如果放任 == 的话，会导致 mid 一直和 left 和 right 相同导致无限递归，进而爆栈。
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, 1 + mid, right);

        // 合并以前将 nums 数组 [left, right] 的数据备份，用于赋值。
        for (int i = left; i <= right; ++i) backup[i] = nums[i];

        // 双指针合并两个数组。
        int pl = left, pr = 1 + mid;

        for (int i = left; i <= right; ++i)
        {
            if (pl > mid)
            {
                nums[i] = backup[pr++];
            }
            else if (pr > right)
            {
                nums[i] = backup[pl++];
            }
            else
            {
                nums[i] = backup[pl] <= backup[pr] ? backup[pl++] : backup[pr++];
            }
        }
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
