/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30404
 *
 * [219] 存在重复元素 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        // 维护一个长度为 k 的滑动窗口。

        std::unordered_set<int> window;
        int left = 0, right = 0;

        while (right < nums.size())
        {
            // 考虑一个特殊情况。[1,2,3,1], k==3，找到第二个 1 的时候，i==0 j==3，但滑动窗口的大小是 3。这样就很好的用将要进来的元素和原来的元素对比，并且他刚好满足边界条件：新进来的元素和要出去的元素满足条件，这是题目允许的。
            if (window.count(nums[right])) return true;

            window.insert(nums[right++]);

            if (right - left > k) window.erase(nums[left++]);
        }


        return false;
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
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
