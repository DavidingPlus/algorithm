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
        std::sort(nums.begin(), nums.end());
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
            if (i + 2 < nums.size() && nums[i] + nums[i + 1] + nums[i + 2] > target) continue;
            // 2. 如果 nums[i] 与后面最大的两个数相加，即 nums[i]+nums[n−2]+nums[n−1] < target，这种情况也不可能匹配成功。
            if (nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;

            auto tuples = twoSumTarget(nums, 1 + i, target - nums[i]);

            // 这个两元组加上 nums[i] 就是一个满足条件的答案。
            for (auto &tuple : tuples)
            {
                tuple.emplace_back(nums[i]);
                res.emplace_back(tuple);
            }

            // XXX 跳过第一个数字重复的段。
            while (i < nums.size() - 1 && nums[i] == nums[1 + i]) ++i;
        }


        return res;
    }

    // 从 nums[start] 开始，计算有序数组 nums 中所有和为 target 的二元组。
    std::vector<std::vector<int>> twoSumTarget(std::vector<int> &nums, int start, int target)
    {
        std::vector<std::vector<int>> res;

        // 数组在前面排过序了，使用双指针解决即可。
        int low = start, high = nums.size() - 1;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            int left = nums[low], right = nums[high];

            // XXX 过程中注意要跳过 low 和 high 的重复段。
            if (sum > target)
            {
                while (low < high && nums[high] == right) --high;
            }
            else if (sum < target)
            {
                while (low < high && nums[low] == left) ++low;
            }
            else
            {
                res.push_back({nums[low], nums[high]});

                while (low < high && nums[high] == right) --high;
                while (low < high && nums[low] == left) ++low;
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
// [1,2,0,1,0,0,0,0]\n
// @lcpr case=end

 */
