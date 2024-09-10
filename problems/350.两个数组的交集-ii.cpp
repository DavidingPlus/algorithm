/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // 两个哈希表即可
        std::unordered_map<int, int> um1, um2;

        for (auto &v : nums1) ++um1[v];
        for (auto &v : nums2) ++um2[v];

        std::vector<int> res;

        for (auto &p1 : um1)
        {
            if (um2.end() != um2.find(p1.first))
            {
                for (int i = 0; i < std::min(p1.second, um2[p1.first]); ++i) res.emplace_back(p1.first);
            }
        }

        return res;
    }
};

// @lc code=end
