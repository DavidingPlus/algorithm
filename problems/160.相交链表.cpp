/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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

#include <bits/stdc++.h>


class Solution
{

public:

    // 思路1：带环的链表，这里的这个函数我们是保证是有环的
    ListNode *detectCycle(ListNode *head)
    {
        // 相遇的时候快指针一定比慢指针多走了一倍
        // 然后我们把其中一个指针指向起点，再相遇的时候就是起点
        // 见 142.png

        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            // TODO 这里不能把 fast != slow 的条件判断放在 while 循环中，因为一开始 fast == slow，也就是循环进不来，需要让他迭代几次再说，因此需要放在里面
            if (fast == slow) break;
        }

        if (!fast || !fast->next) return nullptr;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tailA = headA;
        for (; tailA->next; tailA = tailA->next) tailA = tailA->next;

        tailA->next = headA;

        ListNode *res = detectCycle(headB);

        tailA->next = nullptr;

        return res;
    }

    // 思路2：想一些办法使得两个链表的遍历同时走到公共处
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     // 两个链表先正常遍历，当为空的时候接到另一个链表的开头继续遍历，如果有环，那么前面不同的部分必然会抵消，最后在相交的起点相遇。如果没有环，那么最后出去为空指针

    //     ListNode *pMoveA = headA, *pMoveB = headB;
    //     int count = 0;

    //     while (1)
    //     {
    //         // 有环的出口
    //         if (pMoveA == pMoveB) return pMoveA;

    //         // 无环的出口
    //         if ((!pMoveA || !pMoveB) && 2 == count) return nullptr;

    //         // 正常遍历
    //         if (!pMoveA || !pMoveB)
    //         {
    //             !pMoveA ? pMoveA = headB : pMoveB = headA;
    //             ++count;
    //         }
    //         else
    //         {
    //             pMoveA = pMoveA->next;
    //             pMoveB = pMoveB->next;
    //         }
    //     }

    //     return nullptr;
    // }
};

// @lc code=end
