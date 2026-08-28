/*
 * @lc app=leetcode.cn id=287 lang=cpp
 * @lcpr version=30404
 *
 * [287] 寻找重复数
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
class Solution
{

public:

    int findDuplicate(std::vector<int> &nums)
    {
        // XXX 这题的思路太巧妙了，怎么想到的？？？？？
        // 我们先假设数组长度为 n，每个 nums[i] 都在 [1, n] 范围内，并且不重复。这样如果我采用这样的遍历方式，我把 nums[i] 的值当作我下一个访问的下标去遍历，这样到最后一定不会遇到重复的下标，因为每个位置的值都是不同的。这就类似于链表的正常遍历。
        // 但本题数组长度为 n + 1，且每个 nums[i] 都在 [1, n] 范围内，并且有重复值，因此遇到某两个重复值的时候按照上面描述的遍历方式，必然会陷入循环。这就类似于循环链表的遍历。
        // 这样数组就变成了一条类似链表的路径。由于每个节点只有一个后继，而节点数量又是有限的，所以从下标 0 出发不断跳转时一定会进入环。重复数字表示有两个不同的下标指向同一个节点，这个节点正好是环的入口。因此，本题可以转化为寻找链表环的入口，使用快慢指针即可：先让快慢指针在环内相遇，再把一个指针放回起点，两个指针每次走一步，它们再次相遇的位置就是重复数字。

        int fast = 0, slow = 0;
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];

            if (fast == slow) break;
        }

        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }


        return fast;
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
// [1,3,4,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n
// @lcpr case=end

 */
