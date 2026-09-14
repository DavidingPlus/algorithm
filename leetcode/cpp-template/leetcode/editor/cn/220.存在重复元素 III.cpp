/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=30404
 *
 * [220] 存在重复元素 III
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int indexDiff, int valueDiff)
    {
        // 维护一个长度为 k 的滑动窗口。

        // 因为需要查找第一个大于或者小于目标元素的下标，使用底层是红黑树的 set。
        std::set<int, std::less<int>> window;
        int left = 0, right = 0;

        while (right < nums.size())
        {
            // XXX 这题和 219 题的板子基本一致，区别在于需要判断的是一个范围。

            // lower_bound(x)：>=x，返回第一个大于等于目标值的元素。
            // upper_bound(x)：>x，返回第一个严格大于目标值的元素。

            // 查找略大于 nums[right] 的那个元素。
            auto iter = window.lower_bound(nums[right]);
            if (window.end() != iter && *iter - nums[right] <= valueDiff) return true;

            // 查找略小于 nums[right] 的那个元素。其实就是 iter 的上一个元素，因为 std::set 默认是严格升序的，并且 window 中不存在 nums[right] 的重复元素。
            if (window.begin() != iter-- && nums[right] - *iter <= valueDiff) return true;


            window.insert(nums[right++]);

            if (right - left > indexDiff) window.erase(nums[left++]);
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
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */
