/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30404
 *
 * [31] 下一个排列
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    void nextPermutation(std::vector<int> &nums)
    {
        // 以一个例子说明：158757631。
        // 我们从下一个排列的角度，考虑一下应该动哪些数字。158 不能动，75 7631，7631 已经是这四个数字中的最大值了，所以应该动前面的 75，具体就是 5 这个数字，将其变为 6，最终就是 76 7531，但是这里后面的数字不是最小排列，所以最终答案是 76 1357。
        // 根据这个过程，我们考虑一下 5 是怎么被筛选出来的。筛选的判断条件肯定是顺序或者逆序扫描的过程中，本来是升序或者降序，但是遇到了第一个反过来的，类似的这种判断条件。因为需要找最接近的下一个排列，肯定改数字的右边是更靠近下一个排列的，因此找的条件就是从右边开始向左找起。那么是升序还是降序呢？假设是降序 67，这东西很明显能改为 76，是结束条件而非循环条件，所以是从右向左的升序。从另一个角度讲这一坨的数字也是右边部分排列最大的一个。
        // 找到数字 5 以后，他需要从 75 变成 76，也就是找到右边这坨数字中大于 5 的第一个，然后交换，也就是 75 7631 -> 76 7531。这时候前面的部分已经完成了，只有后面的部分还需要变为最小排列。原来的 6 大于 5 的第一个数字，那么 6 右边的数字已经不会大于 5，6 左边的数字已经也是大于 5 的，因此交换以后的右边这坨数字依然是从右到左升序的，转化为最小排列只需要逆序即可。

        int target = nums.size() - 1;
        while (target - 1 >= 0 && nums[target] <= nums[target - 1]) --target;
        --target;

        // 考虑特殊情况，如果原数组是最大排列，这时候只需要执行最后一步，变成最小排列即可。对应的 target 为 0 时退出循环，最后变为 -1，这时也是兼容最后一步的代码的。
        if (-1 != target)
        {
            int next = nums.size() - 1;
            while (nums[next] <= nums[target]) --next;

            std::swap(nums[next], nums[target]);
        }

        std::reverse(nums.begin() + (target + 1), nums.end());
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
// [1,2]\n
// @lcpr case=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */
