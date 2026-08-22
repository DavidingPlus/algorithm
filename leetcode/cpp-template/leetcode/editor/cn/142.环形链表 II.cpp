/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30404
 *
 * [142] 环形链表 II
 */

#include "_listnode.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{

public:

    ListNode *detectCycle(ListNode *head)
    {
        // 相遇的时候快指针一定比慢指针多走了一倍，然后我们把其中一个指针指向起点，再相遇的时候就是起点。
        // 具体见 142.png。
        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) break;
        }

        if (!fast || !fast->next) return nullptr;

        ListNode *p = head;
        while (p != fast)
        {
            p = p->next;
            fast = fast->next;
        }


        return p;
    }
};
// @lc code=end


int main()
{
}


/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
