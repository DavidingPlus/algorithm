/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */



#include "../common/globalmacros.h"
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

// @lc code=start


class Solution
{

public:

    // TODO 优化算法时间和空间复杂度。

    bool isContain(const std::unordered_map<char, int> &umt, const std::unordered_map<char, int> &umw)
    {
        if (umt.size() > umw.size()) return false;

        for (auto &e : umt)
        {
            // 注意：umw 是 const std::unordered_map & 类型，不能使用 umw[key] 访问元素，因为 operator[] 在 key 不存在时可能插入新元素，因此它不是 const 操作。这里应该使用 find() 查找，并保存返回的迭代器：如果 umw.end() == it，说明字符不存在；否则通过 it->second 获取对应次数，再判断 umw 中该字符的数量是否满足 umt 的要求。这样也避免了对同一个 key 重复查找。
            auto it = umw.find(e.first);
            if (umw.end() == it || e.second > it->second) return false;
        }


        return true;
    }

    std::string minWindow(std::string s, std::string t)
    {
        // 滑动窗口的思想。
        // 我们设置一个区间（算法网站建议左闭右开），使用双指针记录窗口。初始情况 left 和 right 都为 0，然后把 right 往右移动，直到滑动窗口中的字符包含 t 中的每个元素，后续用满足条件替代。这样是一个合理的解，但是这个解不一定是最短窗口子串。这个时候考虑该动哪个指针？显然不是 right，因为 right 往右移动的解虽然满足条件，但是长度更大。left 右移，缩短窗口长度，直到不满足条件，这时候是遍历到当前位置的最优解。这个时候继续考虑该动哪个指针？显然不是 left，因为 left 再往右移动显然不满足条件了。这样一直迭代到遍历完整个字符串，最终得到结果。

        long int len = INTMAX_MAX;
        int start = 0, end = 0;

        // 用一个哈希表记录 t 和滑动窗口，key 是字符 char，data 是当前该字符出现的个数，如果这两个哈希表的内容完全一致，则相等。
        std::unordered_map<char, int> umt, umw;

        for (auto &c : t) ++umt[c];

        // 定义左闭右开的滑动窗口。
        int left = 0, right = 0;
        while (right < s.size())
        {
            if (!isContain(umt, umw)) ++umw[s[right++]];

            while (isContain(umt, umw))
            {
                if (right - left < len)
                {
                    start = left, end = right;
                    len = right - left;
                }

                --umw[s[left++]];
            }
        }


        return INTMAX_MAX != len ? s.substr(start, end - start) : std::string();
    }


    // 旧版代码。
    // bool isContain(const std::unordered_map<char, std::pair<int, int>> &um)
    // {
    //     for (auto &each : um)
    //     {
    //         if (each.second.first < each.second.second)
    //             return false;
    //     }

    //     return true;
    // }

    // std::string minWindow(std::string s, std::string t)
    // {
    //     std::string res;
    //     res.resize(N);

    //     // 滑动窗口的思想，本质其实还是双指针
    //     // 只是我们做了限制，让两个指针什么时候可以有序的右移
    //     // 思路：
    //     // 1.右指针右移，到达可以包含的位置，记录
    //     // 2.左指针右移，尽可能让这个滑动窗口尽量小，直到不满足条件，过程中记录
    //     // 3.右指针继续右移，重复上述工作
    //     // 4.直到右指针移到最右边并且左指针移到不满足条件的最左边

    //     // 这个算法的时间复杂度是O(n)，因为我们只遍历了一遍
    //     std::unordered_map<char, std::pair<int, int>> um; // std::pair中第一个存储现在滑动窗口中的个数，第二个存储t字符串中对应的个数

    //     // 初始化um
    //     for (auto &ch : t)
    //     {
    //         if (0 == um.count(ch)) // count函数，查看key是否存在，存在返回1，不存在返回0
    //             um[ch] = {0, 1};
    //         else
    //             ++um[ch].second;
    //     }

    //     // 这里的滑动窗口，使用左闭右开，这样可以很好的避免边界条件
    //     int left = 0, right = 0;
    //     while (right <= s.size())
    //     {
    //         // 右指针右移
    //         if (1 == um.count(s[right]))
    //             ++um[s[right]].first;
    //         ++right;

    //         if (!isContain(um))
    //             continue;

    //         // 判断是否满足条件
    //         while (1)
    //         {
    //             // 左指针左移直到直到不满足条件
    //             if (1 == um.count(s[left]))
    //                 --um[s[left]].first;
    //             ++left;

    //             if (!isContain(um))
    //                 break;
    //         }

    //         res = (res.size() < right - left + 1) ? res : s.substr(left - 1, right - left + 1);
    //     }

    //     // 如果没找到返回空串
    //     if (N == res.size())
    //         return std::string();
    //     return res;
    // }
};
// @lc code=end


int main()
{
    Solution so;

    std::string s{"ADOBECODEBANC"}, t{"ABC"};

    std::cout << so.minWindow(s, t) << std::endl;
}
