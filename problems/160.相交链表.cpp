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
    // // 思路1：带环的链表，这里的这个函数我们是保证是有环的
    // ListNode *detectCycle(ListNode *head) {
    //     // 快慢指针
    //     auto fast = head, slow = head;
    //     while (fast && fast->next) {
    //         fast = fast->next->next;
    //         slow = slow->next;
    //         if (fast == slow)
    //             break;
    //     }
    //     // 如果没有交点，返回nullptr即可
    //     if (nullptr == fast || nullptr == fast->next)
    //         return nullptr;
    //     // 然后让一根指针回到头部，相交即是环起点
    //     fast = head;
    //     while (fast != slow) {
    //         fast = fast->next;
    //         slow = slow->next;
    //     }
    //     return slow;
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     // 将A的末尾和头部连起来
    //     auto pa = headA;
    //     while (pa->next) pa = pa->next;
    //     pa->next = headA;

    //     // 找环起点
    //     auto p = detectCycle(headB);
    //     pa->next = nullptr;

    //     return p;
    // }

    // 思路2：想一些办法使得两个链表的遍历同时走到公共处
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 我们让两个链表分别遍历，然后为空后指向另一个链表的头部，然后重新开始跑，这样跑出来后面一定会交于相交处第一个位置
        auto pa = headA, pb = headB;
        int count = 0;
        while (pa != pb) {
            // 整个过程中只能有一次pa->next为空，第二次就表明不相交了
            if (pa->next)
                pa = pa->next;
            else {
                pa = headB;
                ++count;
                if (2 == count)
                    return nullptr;
            }
            pb = pb->next ? pb->next : headA;
        }
        return pa;
    }
};
// @lc code=end
