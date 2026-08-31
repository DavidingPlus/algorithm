/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    // 思路 1：找到分段点，然后合并。
    // std::vector<int> sortedSquares(std::vector<int> &nums)
    // {
    //     std::vector<int> res(nums.size());

    //     // 负数的平方可能大于正数的平方，因此原数组可以按照正负数分为两段，一段是负数，一段是非负数。我们找到非负的第一个元素，然后使用双指针进行类似两个链表合并的思路即可。
    //     // TODO 使用二分法替代 std::find_if（练习）。
    //     auto it = std::find_if(nums.begin(), nums.end(), [](int val)
    //                            {
    //                                return val >= 0; //
    //                            });

    //     // 如果找不到非负的第一个元素，代表全是负数。
    //     if (nums.end() == it)
    //     {
    //         for (int i = nums.size() - 1; i >= 0; --i) res[nums.size() - 1 - i] = nums[i] * nums[i];
    //     }
    //     // 如果 it 就是 nums.begin()，代表全是非负数。
    //     else if (nums.begin() == it)
    //     {
    //         for (int i = 0; i < nums.size(); ++i) res[i] = nums[i] * nums[i];
    //     }
    //     // 否则执行两个链表合并思路。
    //     else
    //     {
    //         int left = it - nums.begin() - 1, right = it - nums.begin();
    //         int i = 0;

    //         while (left >= 0 && right < nums.size())
    //         {
    //             res[i++] = std::abs(nums[left]) > std::abs(nums[right])
    //                            ? nums[right] * nums[right++]
    //                            : nums[left] * nums[left--];
    //         }

    //         while (left >= 0) res[i++] = nums[left] * nums[left--];
    //         while (right < nums.size()) res[i++] = nums[right] * nums[right++];
    //     }


    //     return res;
    // }

    // 思路 2：从数组左右两端开始，向中间查找。
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> res(n);

        // 对这个数组而言，左端是绝对值较大的负数，右端是绝对值较大的正数。我们把双指针的起点放在左右两端，每次取平方较大的值，放到结果数组的末尾。这个逻辑对不变号的用例也是成立的。
        int left = 0, right = n - 1;
        int p = n - 1;

        while (left <= right)
        {
            res[p--] = std::abs(nums[left]) > std::abs(nums[right])
                           ? nums[left] * nums[left++]
                           : nums[right] * nums[right--];
        }


        return res;
    }


    // 旧版代码。
    // 升序数组，找到不小于 target 的第一个数。
    // int binarySearch(const std::vector<int> &nums, int target)
    // {
    //     int left = 0, right = nums.size() - 1;
    //     while (left <= right)
    //     {
    //         int mid = left + (right - left) / 2;
    //         if (target == nums[mid])
    //         {
    //             right = mid - 1;
    //         }
    //         else if (nums[mid] > target)
    //         {
    //             right = mid - 1;
    //         }
    //         else
    //         {
    //             left = mid + 1;
    //         }
    //     }

    //     return left <= nums.size() - 1 ? left : -1;
    // }

    // std::vector<int> merge(const std::vector<int> &nums1, std::vector<int> &nums2)
    // {
    //     std::vector<int> res;

    //     int p1 = 0, p2 = 0;
    //     while (p1 < nums1.size() && p2 < nums2.size())
    //     {
    //         if (nums1[p1] <= nums2[p2])
    //         {
    //             res.push_back(nums1[p1] * nums1[p1]);
    //             ++p1;
    //         }
    //         else
    //         {
    //             res.push_back(nums2[p2] * nums2[p2]);
    //             ++p2;
    //         }
    //     }

    //     int &remainP = p1 != nums1.size() ? p1 : p2;
    //     auto &remainNum = p1 != nums1.size() ? nums1 : nums2;
    //     for (; remainP < remainNum.size(); ++remainP)
    //     {
    //         res.push_back(remainNum[remainP] * remainNum[remainP]);
    //     }

    //     return res;
    // }

    // std::vector<int> sortedSquares(std::vector<int> &nums)
    // {
    //     std::vector<int> res(nums.size());

    //     // 如果没有变号，直接依次平方即可，记得负数要反过来
    //     if (nums[0] >= 0 || nums[nums.size() - 1] <= 0)
    //     {
    //         if (nums[0] >= 0)
    //         {
    //             for (int i = 0; i < nums.size(); ++i) res[i] = nums[i] * nums[i];
    //         }
    //         else
    //         {
    //             for (int i = 0; i < nums.size(); ++i) res[i] = nums[nums.size() - i - 1] * nums[nums.size() - i - 1];
    //         }
    //     }
    //     else
    //     {
    //         // 负数平方会变成正数，因此将数组分为 >= 0 和 < 0 的部分，处理以后再做数组的合并即可
    //         int pos = binarySearch(nums, 0);

    //         // 前半部分是负数，要反过来
    //         std::vector<int> nums1(pos);
    //         for (int i = 0; i < pos; ++i)
    //         {
    //             nums1[i] = -nums[pos - i - 1];
    //         }

    //         auto nums2 = std::vector<int>(nums.begin() + pos, nums.end());

    //         res = merge(nums1, nums2);
    //     }

    //     return res;
    // }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
