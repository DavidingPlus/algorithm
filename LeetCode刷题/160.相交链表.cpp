/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                break;
        }

        if (!fast || !fast->next)
            return nullptr;

        // 参考labuladong的解法，巧妙
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 把A链表的首尾连接起来，从B链表看来相交的起始结点就是从B开始遍历的环起点
        ListNode *moveA = headA;
        for (; moveA->next; moveA = moveA->next)
            ;

        // 记录这个结点，后面需要恢复
        ListNode *tmp = moveA;
        tmp->next = headA;

        // 遍历B
        ListNode *ret = detectCycle(headB);

        // 恢复结构
        tmp->next = nullptr;

        return ret;
    }
};
// @lc code=end
