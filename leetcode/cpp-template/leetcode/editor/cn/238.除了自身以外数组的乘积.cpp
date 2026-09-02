/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30404
 *
 * [238] 除了自身以外数组的乘积
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size());

        // 题目要求不能用除法，因此定义从左到右和从右到左的两个前缀积数组。
        std::vector<int> prefix(1 + nums.size(), 1), suffix(2 + nums.size(), 1);
        for (int i = 1; i <= nums.size(); ++i) prefix[i] = prefix[i - 1] * nums[i - 1];
        for (int i = nums.size(); i >= 1; --i) suffix[i] = suffix[i + 1] * nums[i - 1];

        for (int i = 1; i <= nums.size(); ++i) res[i - 1] = prefix[i - 1] * suffix[i + 1];


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
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */
