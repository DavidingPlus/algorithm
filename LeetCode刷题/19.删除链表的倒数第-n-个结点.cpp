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
        ListNode *first = head, *second = head;
        // 先出发的指针先走n，后出发的指针在出发，这样后出发的指针刚好到达目的位置
        while (n--)
            first = first->next;

        while (first) {
            first = first->next;
            second = second->next;
        }

        return second;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 如果是倒数第一个，那么需要特殊处理
        if (1 == n) {
            // 如果就一个元素，那么走下面会出错，返回空即可
            if (nullptr == head->next)
                return nullptr;

            ListNode* q = kthToLast(head, n + 1);
            q->next = nullptr;
        } else {
            ListNode* q = kthToLast(head, n);

            // 删除后面一个节点模拟他被删除的情况
            q->val = q->next->val;
            q->next = q->next->next;
        }

        return head;
    }
};
// @lc code=end
