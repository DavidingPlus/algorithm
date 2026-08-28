/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30404
 *
 * [445] 两数相加 II
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{

public:

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 先反转链表，再执行正常相加逻辑，最后再翻转一次即可。
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode *dummyHead = new ListNode(-1), *pDummy = dummyHead;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;

        while (p1 || p2 || carry)
        {
            int val = carry;

            if (p1)
            {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2)
            {
                val += p2->val;
                p2 = p2->next;
            }

            carry = val / 10;
            val = val % 10;

            pDummy->next = new ListNode(val);
            pDummy = pDummy->next;
        }


        return reverseList(dummyHead->next);
    }

    ListNode *reverseList(ListNode *head)
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;


        return newHead;
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
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */
