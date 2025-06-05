/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 升序数组，找到不小于 target 的第一个数
    int binarySearch(const std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                right = mid - 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left <= nums.size() - 1 ? left : -1;
    }

    std::vector<int> merge(const std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> res;

        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size())
        {
            if (nums1[p1] <= nums2[p2])
            {
                res.push_back(nums1[p1] * nums1[p1]);
                ++p1;
            }
            else
            {
                res.push_back(nums2[p2] * nums2[p2]);
                ++p2;
            }
        }

        int &remainP = p1 != nums1.size() ? p1 : p2;
        auto &remainNum = p1 != nums1.size() ? nums1 : nums2;
        for (; remainP < remainNum.size(); ++remainP)
        {
            res.push_back(remainNum[remainP] * remainNum[remainP]);
        }

        return res;
    }

    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size());

        // 如果没有变号，直接依次平方即可，记得负数要反过来
        if (nums[0] >= 0 || nums[nums.size() - 1] <= 0)
        {
            if (nums[0] >= 0)
            {
                for (int i = 0; i < nums.size(); ++i) res[i] = nums[i] * nums[i];
            }
            else
            {
                for (int i = 0; i < nums.size(); ++i) res[i] = nums[nums.size() - i - 1] * nums[nums.size() - i - 1];
            }
        }
        else
        {
            // 负数平方会变成正数，因此将数组分为 >= 0 和 < 0 的部分，处理以后再做数组的合并即可
            int pos = binarySearch(nums, 0);

            // 前半部分是负数，要反过来
            std::vector<int> nums1(pos);
            for (int i = 0; i < pos; ++i)
            {
                nums1[i] = -nums[pos - i - 1];
            }

            auto nums2 = std::vector<int>(nums.begin() + pos, nums.end());

            res = merge(nums1, nums2);
        }

        return res;
    }
};

// @lc code=end
