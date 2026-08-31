/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=30404
 *
 * [88] 合并两个有序数组
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        // 这个题需要原地修改 nums1，如果从头开始修改的话，nums1 后面的部分会被覆盖掉。但联想到题目为我们预留了一堆 0 做后备空间，我们从后面开始填充即可。对应的 nums1 和 nums2 的双指针起点也应该是 m-1 和 n-1，即有效数据的尾部。
        int i = m - 1, j = n - 1, p = nums1.size() - 1;

        while (i >= 0 && j >= 0) nums1[p--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        // 循环退出的条件可能是 i 或者 j 小于 0，处理剩余部分即可。但由于 nums1 和 nums2 原本有序，如果是 j 小于 0，nums1 前面剩余的部分是自然有序的，不用再排，因此只需考虑 nums2 即可。
        while (j >= 0) nums1[p--] = nums2[j--];
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
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */
