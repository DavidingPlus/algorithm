/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30404
 *
 * [128] 最长连续序列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int longestConsecutive(std::vector<int> &nums)
    {
        int res = 0;

        std::unordered_set<int> us(nums.begin(), nums.end());

        // 注意：这里要用值传递，不能用引用，因为原数组的值不能被修改。
        for (int num : us)
        {
            // XXX 只需要增加一个判断：只有连续序列的起点才向后查找。如果 num - 1 存在，说明当前数字不是起点，直接跳过。这样能保证一个数字最多被查两次，时间复杂度在 O(n) 到 O(2n) 之间。
            if (us.count(num - 1)) continue;

            int len = 0;
            while (us.count(num++)) ++len;

            res = std::max(res, len);
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
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */
