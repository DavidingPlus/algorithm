/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30404
 *
 * [15] 三数之和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), std::less<int>());
        return threeSumTarget(nums, 0);
    }

    std::vector<std::vector<int>> threeSumTarget(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> res;

        // 第一个数理论上可以是 nums 中的任何数，我们先枚举第一个数，然后对第一个数右边的部分用两数之和就行了。为什么是右边的部分呢？因为如果剩余两个数出现在左边，那么相当于是第一个数在前面的某个情况，必然会重复。
        for (int i = 0; i < nums.size(); ++i)
        {
            // XXX 从别人题解学的两个优化。

            // 1. 如果 nums[i] 与后面最小的两个数相加，即 nums[i]+nums[i+1]+nums[i+2] > target，这种情况不可能匹配成功。
            if (2 + i < nums.size() && nums[i] + nums[1 + i] + nums[2 + i] > target) continue;
            // 2. 如果 nums[i] 与后面最大的两个数相加，即 nums[i]+nums[n−2]+nums[n−1] < target，这种情况也不可能匹配成功。
            if (nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;

            // 题目要求：判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == target。nums[i]，nums[j] 和 nums[k] 是可能相等的，因此这里无需跳过 i 相同的部分。
            auto tuples = twoSumTarget(nums, 1 + i, target - nums[i]);

            // 这个两元组加上 nums[i] 就是一个满足条件的答案。
            for (auto &tuple : tuples)
            {
                tuple.emplace_back(nums[i]);
                res.emplace_back(tuple);
            }

            // XXX 当前已获得所有 [i, j, k] 的答案，接下来的遍历自然需要跳过 i 相同的部分，避免添加重复答案。
            while (1 + i < nums.size() && nums[i] == nums[1 + i]) ++i;
        }


        return res;
    }

    // 从 nums[start] 开始，计算有序数组 nums 中所有和为 target 的二元组。
    std::vector<std::vector<int>> twoSumTarget(std::vector<int> &nums, int start, int target)
    {
        // 对于已排序数组的两数之和，自然使用双指针的思路。
        std::vector<std::vector<int>> res;

        int left = start, right = nums.size() - 1;
        while (left < right)
        {
            // XXX 过程中注意要跳过 low 和 high 的重复段。

            int leftVal = nums[left], rightVal = nums[right], sum = leftVal + rightVal;

            if (sum > target)
            {
                while (left < right && rightVal == nums[right]) --right;
            }
            else if (sum < target)
            {
                while (left < right && leftVal == nums[left]) ++left;
            }
            else
            {
                res.push_back({nums[left], nums[right]});
                while (left < right && leftVal == nums[left]) ++left;
                while (left < right && rightVal == nums[right]) --right;
            }
        }


        return res;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,1,0,0,0,0]\n
// @lcpr case=end

 */
