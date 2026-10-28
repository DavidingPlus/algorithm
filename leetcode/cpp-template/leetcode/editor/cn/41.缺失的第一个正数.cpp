/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30404
 *
 * [41] 缺失的第一个正数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int firstMissingPositive(std::vector<int> &nums)
    {
        int n = nums.size();

        // 参考思路：https://leetcode.cn/problems/first-missing-positive/solutions/7703/tong-pai-xu-python-dai-ma-by-liweiwei1419/
        // 假设数组长度为 n，如果数组是 [1, 2, 3, ..., n] 或者这些值的其他排序数组，那么答案就是 1 + n。只要其中有任何一个数不是范围内的值，答案就是缺失的那个值，因此我们只关心 [1, n] 的值。
        // 其次，最直观的想法肯定是构造一个哈希表，将元素放进去，然后从头看一下哪个数没有出现，就是答案。但是题目要求 O(1) 的空间复杂度，因此如果要从这个思路出发，必须考虑数组本身作为哈希表，也就是参考思路提到的原地哈希。
        // XXX 本题中原地哈希的思路是，由于我们只关心 [1, n] 的元素，因此可以把他们映射到 [0, n - 1] 的下标中，也就是我们期望 3 这个元素放在下标 2 的位置。在遍历的过程中，如果遇到 5，我们优先把 5 这个元素和下标 4 的元素交换，然后再处理交换过来的元素，直到处理到范围外的值。按照这个思路往下处理，最后外层顺序遍历结束以后，所有该在指定位置的元素都在指定位置了，这时重新从头部遍历，第一个范围外的下标 + 1 就是答案，如果都在指定位置，答案就是 1 + n。
        // 另外考虑一下内层循环交换的时间复杂度，每交换一次就至少有一个数被放在正确位置，因此整个算法过程最多交换 n 次，平均到每次内层循环上是 1 次，总共时间复杂度是 O(n)。

        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != 1 + i)
            {
                // nums[i] != 1 + i 是当前 i 位置很直观的判断条件，但是我们把 nums[i] 这个值的元素放在它对应的 nums[i] - 1 下标，也就是下面的交换操作时，看起来没问题，但是如果 nums[i] == nums[nums[i] - 1] 时，就会导致死循环，这时应该直接 break，例如测试用例 [1, 1]，需要特殊处理这种情况。假设 nums[i] == p，如果 nums[i] == nums[p - 1] == p，那么至少 p - 1 的位置是正确的。不会出现两个位置相等但都不正确的情况。
                if (nums[i] == nums[nums[i] - 1]) break;

                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (1 + i != nums[i]) return 1 + i;
        }


        return 1 + n;
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
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */
