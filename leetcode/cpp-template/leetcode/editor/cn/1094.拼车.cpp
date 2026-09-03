/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

constexpr int N = 1000;


class Solution
{

public:

    bool carPooling(std::vector<std::vector<int>> &trips, int capacity)
    {
        std::vector<int> nums(1 + N, 0);
        Difference df(nums);

        for (auto &trip : trips)
        {
            // 第 trip[1] 站乘客上车，第 trip[2] 站乘客已经下车，即乘客在车上的区间是 [trip[1], trip[2] - 1]。
            int val = trip[0], i = trip[1], j = trip[2] - 1;
            df.increment(i, j, val);
        }

        std::vector<int> res = df.result();
        for (auto &e : res)
        {
            if (e > capacity) return false;
        }


        return true;
    }


    class Difference
    {

    public:

        Difference(std::vector<int> &nums)
        {
            diff.resize(nums.size());
            diff[0] = nums[0];

            for (int i = 1; i < nums.size(); ++i) diff[i] = nums[i] - nums[i - 1];
        }

        void increment(int i, int j, int val)
        {
            diff[i] += val;
            if (1 + j < diff.size()) diff[1 + j] -= val;
        }

        std::vector<int> result()
        {
            std::vector<int> res(diff.size());
            res[0] = diff[0];

            for (int i = 1; i < diff.size(); ++i) res[i] = res[i - 1] + diff[i];


            return res;
        }


    private:

        std::vector<int> diff;
    };
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
