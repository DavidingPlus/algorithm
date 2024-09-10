/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    // 给 array<int, 26> 自定义一个 hash 函数，当然这里是 functor
    struct ArrayHash
    {
        // 这里不加上 const 限定符会导致下面使用的时候编译错误，可能在调用 hash functor 的时候编译器做了限制，以后写算法写这种 functor 都加上就行
        size_t operator()(const std::array<int, 26> &arr) const
        {
            size_t seed = 0;

            // 目的是为了让其足够混乱，公式来源于侯捷老师的课程
            for (int i = 0; i < 26; ++i) seed ^= std::hash<int>()(arr[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

            return seed;
        }
    };

    std::array<int, 26> getHash(const std::string &s) const
    {
        std::array<int, 26> res;
        std::fill(res.begin(), res.end(), 0); // 记得要赋值为 0，否则是随机数

        for (auto &c : s) ++res[c - 'a'];

        return res;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHash> um;

        for (auto &s : strs)
        {
            auto key = getHash(s);

            if (um.end() != um.find(key))
            {
                um[key].emplace_back(s);
            }
            else
            {
                um[key] = {s};
            }
        }

        std::vector<std::vector<std::string>> res;
        for (auto &p : um) res.emplace_back(p.second);

        return res;
    }
};

// @lc code=end
