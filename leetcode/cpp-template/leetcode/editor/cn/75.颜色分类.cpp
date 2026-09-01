/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30404
 *
 * [75] 颜色分类
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    // 解法 1：计数排序。
    // 用一个 count 数组去记录元素的值以及出现的次数，下标是元素的值相对原数组最小值的偏移（因为原数组最小值可能不为 0，我们要保证相对语义），存储的内容就是出现的次数。
    // void sortColors(std::vector<int> &nums)
    // {
    //     // 计算原数组最大和最小值。
    //     int minVal = *std::min_element(nums.begin(), nums.end()), maxVal = *std::max_element(nums.begin(), nums.end());

    //     // 定义 count 数组。
    //     std::vector<int> count(maxVal - minVal + 1);
    //     for (auto &e : nums) ++count[e - minVal];

    //     int i = 0;
    //     for (int j = 0; j < count.size(); ++j)
    //     {
    //         while (count[j]--) nums[i++] = j + minVal;
    //     }
    // }

    // 解法 2：双指针。
    // 本题中 nums 只会出现 0, 1, 2 三种数字，我们可以充分利用这一点。
    void sortColors(std::vector<int> &nums)
    {
        /*
         * 使用三个指针维护四个区域：
         *
         *     [0, left)       已经确定为 0
         *     [left, p)      已经确定为 1
         *     [p, right]      尚未处理
         *     (right, n)      已经确定为 2
         * p 指向当前正在处理的位置，left 用来把 0 放到左侧，right 用来把 2 放到右侧。
         * 这里理解两个交换操作的关键，不是交换本身，而是交换后换回来的数据是否已经处理过。
         *
         * left 一定不会超过 p。因此，当 nums[p] == 0 时，把 nums[p] 和 nums[left] 交换，
         * 从 left 位置换回来的数据来自 p 左侧，也就是 p 之前已经走过、已经正确处理过的部分。
         * 这个数据不需要再次检查，所以交换后可以同时执行 left++ 和 p++。
         * 如果 left == p，则是当前位置和自己交换，也同样可以直接向后移动。
         *
         * 当 nums[p] == 1 时，1 不需要交换，直接执行 p++ 即可。
         *
         * 当 nums[p] == 2 时，把 nums[p] 和 nums[right] 交换。此时 right 位置来自 p 的右侧，
         * 在遍历过程中还没有被 p 检查过，因此换回 p 的数据仍然是未处理数据，可能是 0、1 或 2。
         * 所以这里只能执行 right--，而不能执行 p++，必须留在当前位置重新判断换回来的数据。
         *
         * 例如 [1, 2, 0]：
         *
         *     p 指向 1：             [1, 2, 0]，1 已经处理，p 右移；
         *     p 指向 2：交换右侧 0， [1, 0, 2]，0 来自未处理区域，所以 p 不动；
         *     p 重新处理 0：交换左侧已处理数据，[0, 1, 2]，此时 p 才能继续右移。
         *
         * 如果处理 2 后错误地让 p++，换回来的 0 就会被跳过，数组会停留在 [1, 0, 2]。
         */
        int left = 0, right = nums.size() - 1;
        int p = 0;

        while (p <= right)
        {
            if (0 == nums[p])
            {
                std::swap(nums[left++], nums[p++]);
            }
            else if (2 == nums[p])
            {
                // XXX 重点理解这一行。
                std::swap(nums[right--], nums[p]);
            }
            else
            {
                ++p;
            }
        }
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
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */
