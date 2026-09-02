/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30404
 *
 * [303] 区域和检索 - 数组不可变
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class NumArray
{

public:

    // 标准前缀和模板。

    NumArray(std::vector<int> &nums)
    {
        // 为了统一首元素的语义，在头部增加一个 dummyHead，因此 preSum[2] 代表的是 [nums[0], nums[1]] 的和。
        preSum.resize(1 + nums.size(), 0);

        for (int i = 1; i <= nums.size(); ++i) preSum[i] = nums[i - 1] + preSum[i - 1];
    }

    int sumRange(int left, int right) { return preSum[1 + right] - preSum[left]; }


    std::vector<int> preSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end


int main()
{
}


/*
// @lcpr case=start
// ["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]\n
// @lcpr case=end

 */
