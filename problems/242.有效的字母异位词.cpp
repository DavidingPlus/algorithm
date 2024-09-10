/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    bool isAnagram(std::string s, std::string t)
    {
        // 本来是可以用两个数组做一个哈希然后判断的，因为需要判断相等，因此起初的想法是使用 std::vector<int> 存储。但其实只需要一个静态数组即可，s 的值 ++，t 的值 -- 即可。如果满足，最后数组的所有元素一定是 0，这里面的 0 有两个都没有的初始值，也有相互抵消的结果，反正如果不为 0，就代表一定有一个多了

        int hash[26] = {0};

        for (auto &c : s) ++hash[c - 'a'];
        for (auto &c : t) --hash[c - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            if (hash[i]) return false;
        }

        return true;
    }
};

// @lc code=end
