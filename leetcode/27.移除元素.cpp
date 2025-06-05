/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include <bits/stdc++.h>


class Solution
{

public:

    int removeElement(std::vector<int> &nums, int val)
    {
        // 快慢指针，快指针给慢指针赋值，慢指针只有在被赋值之后才会前进
        // 在这个过程中肯定是后面的填充前面的，不用担心前面的值被覆盖，因为在覆盖之前他们的值肯定已经前移了，最极端的情况，没有 val 的值，那就相当于每个位置自身赋值了一次
        int fast = 0, slow = 0;

        // TODO 遍历记得写 < size 而不是 <= size - 1，因为 size() 接口是 size_t 类型，如果是空数组 - 1，就成 -1 的补码了，细节。。。
        while (fast < nums.size())
        {
            // 不相等则快指针给慢指针赋值
            if (val != nums[fast])
            {
                nums[slow++] = nums[fast];
            }
            // 相等则代表需要删除的 val，也就是不需要赋值
            ++fast;
        }

        return slow;
    }
};

// @lc code=end
