/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=30404
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int minOperations(std::vector<int> &nums, int x)
    {
        // 每次操作的时候，只能移动 nums 最边上的元素，因此剩余的部分一定是一段连续的子数组。由于数组整体的和是确定的，x 是确定的，因此剩余部分的和是确定的。最小操作数也就等价于寻找一段连续子数组，使得和为 target，并且长度最大。
        // 由于 nums[i] >= 1，都为正数，因此可以完美使用滑动窗口的思路。
        int sum = 0;
        for (auto &e : nums) sum += e;
        int target = sum - x;

        int left = 0, right = 0;
        int windowSum = 0, res = std::numeric_limits<int>::min();

        // 窗口使用左闭右开区间 [left, right)：
        //
        //     left  指向窗口中的第一个元素；
        //     right 指向窗口末尾的下一个位置，不属于窗口。
        //
        // 外层 right < nums.size() 表示右侧还有元素没有加入窗口，因此 nums[right] 仍然是合法位置。执行 nums[right++] 后，right 可能等于 nums.size()，这时 right 只是数组末尾的边界，不能再把它当成元素下标访问，若边界条件去等，会访问 nums[nums.size()] 导致越界。
        while (right < nums.size())
        {
            windowSum += nums[right++];

            // 当窗口和大于 target 时，从左侧收缩窗口。left < right 表示当前窗口 [left, right) 非空，因此 nums[left] 确实属于窗口，可以安全移除。
            // 这里不能写成 left <= right：当 left == right 时窗口已经为空，再访问 nums[left] 就是在处理窗口外的元素，甚至可能发生越界。
            // 例如 nums = [1, 1]、x = 3 时，target = -1，窗口最终会收缩为空。
            while (left < right && windowSum > target) windowSum -= nums[left++];

            if (target == windowSum) res = std::max(res, right - left);
        }


        return std::numeric_limits<int>::min() == res ? -1 : nums.size() - res;
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
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n3\n
// @lcpr case=end

 */
