/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30404
 *
 * [11] 盛最多水的容器
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    int maxArea(std::vector<int> &height)
    {
        // 从遍历的角度来讲，本题需要找到每两条线能存储水量的最大值，计算公式是：两条线的横坐标之差 * 两条线高度较小的那个。
        // 假设某个时候位于 [i, j] 的位置，如何迭代到下一个状态呢？假如 height[i] < height[j]，那么 j 往左的位置计算出的结果一定是小于当前位置的，因此这部分都可以被排除。因此，可以使用双指针的思路，根据前面的判断条件移动双指针。

        // XXX 两边高度相等时，为什么可以任选一边移动？
        // 设当前边界是 L、R，两端高度都是 h，当前面积 A = h * (R - L)，先把 A 计入 res。若选择 right--，被排除的是所有使用原右端 R 的组合 (k, R)，其中 L < k < R。它们的面积 min(height[k], h) * (R - k) <= h * (R - k) <= A，都无法超过已记录的答案。选择 left++ 同理：所有使用原左端 L 的内部组合，面积也都不超过 A。但注意不能直接返回：换掉两条旧边界后，内部两条更高的线仍然可能组成更大的容器。
        // 两种选择之后，实际遍历的组合可能不同，会不会因此遗漏更优的内部组合？内部组合的宽度更小，要超过 A，两条线的高度必须都严格大于 h。如果内部比 h 高的线不足两条，就不可能超过 A，两种路线即使不同也不会漏掉更优答案。
        // 如果至少有两条，记 p 为从左向内遇到的第一条比 h 高的线，q 为从右向内遇到的第一条，p < q。
        // 无论最初选 left++ 还是 right--，两条路线都会先到达同一个内部状态 (p, q)：
        // 1. 若左指针先到 p，它的高度已大于 h，而右指针尚未到 q，右端高度一定不超过 h。此时右边更矮，只会继续移动右指针；左指针停在 p，直到右指针到达 q。
        // 2. 若右指针先到 q，同理，它会停在 q，直到左指针到达 p。
        // 因此，哪个指针先找到更高的线，哪个就会停住，等待另一边也找到更高的线。到达 (p, q) 之前，至少一端的高度不超过 h，宽度也不超过 R - L，所以面积都不超过 A。两条路线到达 (p, q) 时，候选区间相同，res 也相同；采用相同的后续规则，遍历就相同。

        // 例子：height = {3, 1, 100, 80, 2, 3}，初始 A = 15，p = 2，q = 3。
        // 下列每项表示“(左下标, 右下标): 面积”。
        // 先 left++：
        // (0,5):15 -> (1,5):4 -> (2,5):9 -> (2,4):4 -> (2,3):80。
        // 先 right--：
        // (0,5):15 -> (0,4):8 -> (0,3):9 -> (1,3):2 -> (2,3):80。
        // 中间检查的组合确实不同，但面积都不超过 15；两条路线最终都到达 (2,3)，找到面积 80。

        int res = 0;
        int left = 0, right = height.size() - 1;

        while (left < right)
        {
            res = std::max(res, (right - left) * std::min(height[left], height[right]));

            // 等高时选择移动右边；本轮面积已记录，排除旧边界不会漏掉更优答案。
            height[left] < height[right] ? ++left : --right;
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
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
