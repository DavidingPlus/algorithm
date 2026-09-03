/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

class Solution
{

public:

    // 想对数组进行某个区间的修改，就可以用到差分数组（就是前缀和数组逆向的原数组）。
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>> &bookings, int n)
    {
        std::vector<int> nums(n, 0);
        Difference df(nums);

        for (auto &booking : bookings)
        {
            int i = booking[0] - 1, j = booking[1] - 1, val = booking[2];
            df.increment(i, j, val);
        }


        return df.result();
    }


    // 差分数组工具类。
    class Difference
    {

    public:

        // 输入一个初始数组，区间操作将在这个数组上进行。
        Difference(std::vector<int> &nums)
        {
            // 差分数组一般是不加 dummyHead 的，因为原数组 nums 相减得到差分数组的值，要补也是 nums 补 dummyHead。
            diff.resize(nums.size());
            diff[0] = nums[0];

            for (int i = 1; i < nums.size(); ++i) diff[i] = nums[i] - nums[i - 1];
        }

        // 给闭区间 [i, j] 增加 val（可以是负数）。
        void increment(int i, int j, int val)
        {
            diff[i] += val;
            if (1 + j < diff.size()) diff[1 + j] -= val;
        }

        // 返回结果数组。
        std::vector<int> result()
        {
            std::vector<int> res(diff.size());
            res[0] = diff[0];

            // 原数组的每个元素就是差分数组对应的前缀和。因为差分数组和前缀和数组的语义是逆过程。
            for (int i = 1; i < diff.size(); ++i) res[i] = res[i - 1] + diff[i];


            return res;
        }


    private:

        // 差分数组。
        std::vector<int> diff;
    };
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
