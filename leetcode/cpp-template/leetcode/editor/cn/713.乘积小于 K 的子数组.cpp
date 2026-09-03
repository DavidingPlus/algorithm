/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30404
 *
 * [713] 乘积小于 K 的子数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int numSubarrayProductLessThanK(std::vector<int> &nums, int k)
    {
        // 数组元素的取值和 k 都是非负数，因此可以使用滑动窗口。

        int left = 0, right = 0;
        int windowMulti = 1, res = 0;

        while (right < nums.size())
        {
            windowMulti *= nums[right++];

            while (left < right && windowMulti >= k) windowMulti /= nums[left++];

            // 走到这里，当前区间 [left, right) 一定是满足条件的。外层的每次循环对应一个 right 位置，内部的每次循环保证 left 最后会出现在满足条件的最靠左的位置，因此当前 right 位置对应的满足条件的个数就能计算了。
            res += right - left;
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
// [10, 5, 2, 6]\n100\n
// @lcpr case=end

/*
// @lcpr case=start
// [686, 28, 455, 675, 605, 29, 942, 48, 502, 889, 854, 206, 231, 796, 272, 565, 887, 969, 558, 13, 22, 455, 145, 804, 15]\n515854\n
// @lcpr case=end

// @lcpr case=start
// [542, 433, 935, 193, 280, 849, 122, 107, 688, 913, 31, 311, 814, 507, 596, 109, 340, 981, 662, 145, 955, 692, 659, 46, 276, 734, 177, 727, 329, 320, 93, 78, 451, 129, 226, 491, 595, 175, 894, 662, 699, 871, 340, 375, 98, 38, 414, 306, 20, 548, 459, 577, 626, 942, 92, 322, 665, 497, 593, 877, 247, 487, 67, 320, 78, 775, 431, 193, 175, 957, 926, 816, 776, 967, 600, 114, 474, 810, 513, 43, 586, 559, 880, 540, 122, 95, 408, 621, 850, 598]\n425740\n
// @lcpr case=end

 */
