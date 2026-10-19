/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30404
 *
 * [18] 四数之和
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, long target)
    {
        std::sort(nums.begin(), nums.end(), std::less<int>());
        return nSumTarget(nums, 4, 0, target);
    }

    // 直接写一个 n 数之和的模板。这个板子假设数组已经有序，为节省时间，排序逻辑在外层执行。
    std::vector<std::vector<int>> nSumTarget(std::vector<int> &nums, int n, int start, long target)
    {
        // n 数之和的思路完全参考 15 题三数之和，把该问题划分为结构相似的子问题，先枚举第一个数，然后求后面部分的 (n-1) 数之和，最后组合起来。当问题简化为两数之和的时候，就用双指针处理。

        std::vector<std::vector<int>> res;

        // 本函数要求至少是两数之和，且数组大小不应该小于 n。
        if (n < 2 || n > nums.size()) return res;

        if (n > 2)
        {
            for (int i = start; i < nums.size(); ++i)
            {
                auto tuples = nSumTarget(nums, n - 1, 1 + i, target - nums[i]);

                for (auto &tuple : tuples)
                {
                    tuple.emplace_back(nums[i]);
                    res.emplace_back(tuple);
                }

                while (1 + i < nums.size() && nums[i] == nums[1 + i]) ++i;
            }
        }
        else
        {
            int left = start, right = nums.size() - 1;
            while (left < right)
            {
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
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
