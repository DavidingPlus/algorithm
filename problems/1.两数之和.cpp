/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 解法 1：暴力
    // std::vector<int> twoSum(std::vector<int> &nums, int target)
    // {
    //     int n = nums.size();

    //     for (int i = 0; i < n; ++i)
    //     {
    //         for (int j = 1 + i; j < n; ++j)
    //         {
    //             if (target == nums[i] + nums[j]) return {i, j};
    //         }
    //     }

    //     return {};
    // }

    // 解法 2：哈希表
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // 可以按顺序遍历，将遍历过的元素存储在哈希表（不需要有序，因此选择哈希表而非红黑树）中，需要存储元素值（key）和下标（data），然后后面进来的数判断哈希表中有没有元素加起来符合题目条件的

        int n = nums.size();

        std::unordered_map<int, int> um;
        for (int i = 0; i < n; ++i)
        {
            // 这里看起来会涉及到一个问题，就是元素重复的问题，哈希表存储的时候会进行覆盖。看起来这里会有一定的问题，但是其实不然。首先题目保证了只有一组解，那么如果两个相同的数组成答案，那么就不会覆盖；如果是两个不同的数组成答案，而其中的某个数有两个或者多个，这种情况是不存在的，因为只有一组解，因此不用担心哈希表的使用出现问题

            if (um.end() != um.find(target - nums[i])) return {um[target - nums[i]], i};

            um[nums[i]] = i;
        }

        return {};
    }
};

// @lc code=end
