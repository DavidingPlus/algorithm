/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=30404
 *
 * [1004] 最大连续1的个数 III
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int longestOnes(std::vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int res = 0;

        while (right < nums.size())
        {
            if (0 == nums[right++]) --k;

            // 结合例子来理解边界条件，[1, 1, 1, 0, 0, 0] 当遇到第三个 0 的时候，才需要开始收缩窗口，这个时候 k 为 -1，因此不能取等。
            while (left < right && k < 0)
            {
                if (0 == nums[left++]) ++k;
            }

            res = std::max(res, right - left);
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
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */
