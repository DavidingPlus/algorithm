/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:

    // 参考了 labuladong 的单调队列题目的板子，可以参考。
    class MonotonicQueue
    {

    public:

        // 维护从队首到队尾非递增的候选最大值队列，允许相等元素，队首就是当前窗口的最大值。例如先进入 1，再进入 3：3 更大，而且比 1 更晚离开窗口，因此可以淘汰 1。接着进入 -1：虽然它比 3 小，但比 3 更晚离开，之后可能成为最大值，所以要保留。此时队列为 [3, -1]。队列只保存仍可能成为最大值的元素，不一定包含窗口中的全部元素。

        void push(int n)
        {
            // 从队尾淘汰严格小于 n 的候选值：n 更大且更晚离开，它们之后不会成为最大值。
            // XXX 注意：相等元素必须保留，因为这里只存数值，pop(n) 也只能按数值移除旧元素。例如 nums = [1, 1, 0]，k = 2，前两个 1 入队后应保留为 [1, 1]。若提前淘汰旧 1，旧 1 滑出时执行 pop(1)，就会误删仍在窗口内的新 1。
            while (!m_d.empty() && m_d.back() < n) m_d.pop_back();
            // 然后将 n 加入尾部。
            m_d.push_back(n);
        }

        // 队列非递增，因此直接读取队首即可得到当前窗口的最大值。
        int max() { return m_d.front(); }

        // n 是原数组窗口中即将离开的最左侧元素。如果它仍在候选队列中，就一定在队首，删除一份即可，后面相等的元素继续保留。如果队首不等于 n，说明 n 之前已被更晚进入且更大的元素淘汰，无需再次删除。
        void pop(int n)
        {
            if (n == m_d.front()) m_d.pop_front();
        }


    private:

        std::deque<int> m_d;
    };


    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        MonotonicQueue window;
        std::vector<int> res;

        int left = 0, right = 0;
        while (right < nums.size())
        {
            window.push(nums[right++]);

            if (right - left == k)
            {
                res.push_back(window.max());

                window.pop(nums[left++]);
            }
        }


        return res;
    }


    // 旧版代码。
    // // 解法1：正统的滑动窗口
    // std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    // {
    //     // 为了提升效率不让每次都寻找窗口里面的最大值，我们保证队列进来的数字一定是比队列头部小的，如果大的话就循环出队列直到新进来的值是最大的
    //     // 因为新进来的比旧的后出去，也就是说就算他们一起参与比较，肯定是新的胜出，并且旧的先出去，所以不用担心新的比他们先出去而考虑不全面的问题，因此我们可以放心弹出
    //     std::vector<int> res;
    //     std::deque<std::pair<int, int>> d;

    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         // 前面的分析有一些疏漏的地方，就是队列新进来的数字一定必须是队列里面最小的，例如 3 1 ，进来2，这个1一样没有用处，所以我们从尾部开始判断，因此改用std::deque

    //         // 判断数量超出，不能简单的看d的个数，因为中间很可能有很多个因为值不对而没有进来，导致这个判断错误
    //         if (!d.empty() && (k == i - d.front().second))
    //             d.pop_front();

    //         // 然后再看大小关系
    //         while (!d.empty() && d.back().first <= nums[i])
    //             d.pop_back();

    //         d.emplace_back(nums[i], i);

    //         // 前几次的压入是不算最大值的
    //         if (i >= k - 1)
    //             res.push_back(d.front().first);
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
