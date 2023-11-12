/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    // // 思路1：循环链表
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode *fast = head, *slow = head;
    //     while (fast and fast->next) {
    //         fast = fast->next->next;
    //         slow = slow->next;
    //         if (fast == slow)
    //             break;
    //     }
    //     if (nullptr == fast or nullptr == fast->next)
    //         return nullptr;

    //     fast = head;
    //     while (fast != slow) {
    //         fast = fast->next;
    //         slow = slow->next;
    //     }
    //     return fast;
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     // 我把其中一个链表的头部和尾部接上，问题就变为了求环形链表的起点了
    //     ListNode *la = headA;
    //     while (la->next)
    //         la = la->next;

    //     la->next = headA;

    //     ListNode *ret = detectCycle(headB);

    //     la->next = nullptr;  // 恢复原始结构

    //     return ret;
    // }

    // 思路2：想一些办法使得两个链表的遍历同时走到公共处
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 我们让两个链表分别遍历，然后为空后指向另一个链表的头部，然后重新开始跑，这样跑出来后面一定会交于相交处第一个位置
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};
// @lc code=end
