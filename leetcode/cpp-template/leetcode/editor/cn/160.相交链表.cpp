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

    // // 思路1：带环的链表，这里的这个函数我们是保证是有环的。我们把链表 A 的末尾和链表 B 的开头链接起来，这样新链表 A 中环的起点就是原始两个链表的交点。
    // ListNode *detectCycle(ListNode *head)
    // {
    //     ListNode *fast = head, *slow = head;
    //     while (fast && fast->next)
    //     {
    //         fast = fast->next->next;
    //         slow = slow->next;

    //         if (fast == slow) break;
    //     }

    //     if (!fast || !fast->next) return nullptr;

    //     ListNode *p = head;
    //     while (p != fast)
    //     {
    //         p = p->next;
    //         fast = fast->next;
    //     }


    //     return fast;
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     ListNode *pA = headA;
    //     while (pA->next) pA = pA->next;

    //     pA->next = headB;

    //     ListNode *res = detectCycle(headA);

    //     pA->next = nullptr;


    //     return res;
    // }

    // 思路2：想一些办法使得两个链表的遍历同时走到公共处。
    // 两个链表先自己正常遍历，当走到为空的时候接到另一个链表的开头继续遍历，如果有环，最后必然在相交的起点相遇，因为这时候走的长度是各自链表交点前面的距离之和加上相交的起点之后的距离。如果没有环，那么最后出去为空指针，并且根据距离计算，二者也是同时出去的。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pA = headA, *pB = headB;
        // 为了区分空指针代表的是哪种语义，使用 count 计数。
        int count = 0;

        // 如果 A、B 相遇，那肯定是相交起点，这时 pA == pB。这里有一种特殊情况，就是 A、B 链表前面部分长度相同，因此第一轮就直接相遇结束了，不影响整体逻辑。
        // 如果没有环，A、B 第二轮同时走到链表末尾，这时同样 pA == pB，二者均为空指针。
        while (pA != pB)
        {
            // 为了兼顾没有环的空指针的情况，判断条件应该是 p 而不是 p->next，这样才能有机会为空。
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA;
    }
};

// @lc code=end


int main()
{
}
