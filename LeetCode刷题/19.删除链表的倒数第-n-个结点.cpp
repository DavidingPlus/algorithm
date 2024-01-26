/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
#include <iostream>
using namespace std;

class Solution {
public:
    // 先找到倒数第n个节点，双指针
    ListNode* kthToLast(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        // 先出发的指针先走n，后出发的指针在出发，这样后出发的指针刚好到达目的位置
        while (n--)
            p1 = p1->next;

        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 如果链表长度为1，那么肯定返回为空，这是一个特殊情况
        if (nullptr == head->next)
            return nullptr;

        // 删除后一个节点来模拟该节点被删除的情况，所以需要对最后一个节点做特殊处理
        if (1 == n) {
            auto p = kthToLast(head, n + 1);
            p->next = nullptr;
        } else {
            auto p = kthToLast(head, n);

            p->val = p->next->val;
            p->next = p->next->next;
        }
        return head;
    }
};
// @lc code=end
