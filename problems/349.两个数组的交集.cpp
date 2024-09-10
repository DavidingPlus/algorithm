/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> um1;

        for (auto &v : nums1) ++um1[v];

        std::unordered_set<int> resUs;
        for (auto &v : nums2)
        {
            if (um1.end() != um1.find(v)) resUs.emplace(v);
        }

        // TODO 容器可以拿别的类型不同的迭代器进行初始化，只要保证传入参数的迭代器类型比当前类更父类即可。std::vector 是 random_access_iterator，std::unordered_set 是 forward_iterator，random_access_iterator 继承自 forward_iterator，所以可以初始化。反过来就不行，因为 forward_iterator 不具有 random_access_iterator 的随机访问的功能。
        return std::vector<int>(resUs.begin(), resUs.end());
    }
};

// @lc code=end
