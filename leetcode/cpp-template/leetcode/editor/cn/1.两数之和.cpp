/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    // 解法 1：暴力。
    // std::vector<int> twoSum(std::vector<int> &nums, int target)
    // {
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         for (int j = 1 + i; j < nums.size(); ++j)
    //         {
    //             if (target == nums[i] + nums[j]) return {i, j};
    //         }
    //     }


    //     return {};
    // }

    // 解法 2：哈希表。可以按顺序遍历，将遍历过的元素存储在哈希表（不需要有序，因此选择哈希表而非红黑树）中，需要存储元素值（key）和下标（data），然后后面进来的数判断哈希表中有没有元素加起来符合题目条件的。
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // 这里看起来会涉及到一个问题，就是元素重复的问题，哈希表存储的时候会进行覆盖。看起来这里会有一定的问题，但是其实不然。首先题目保证了只有一组解，那么如果两个相同的数组成答案，那么就不会覆盖；如果是两个不同的数组成答案，而其中的某个数有两个或者多个，这种情况是不存在的，因为只有一组解，因此不用担心哈希表的使用出现问题。

        std::unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 判断是否存在模式为 [x, i]（第二个元素是 i）的答案。并且我们这里保证 x < i，至于 x > i 的情况，[i, x] 的后面遍历过程中会遇到，所以总体遍历不会丢失数据。
            if (um.count(target - nums[i])) return {um[target - nums[i]], i};

            um[nums[i]] = i;
        }


        return {};
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
