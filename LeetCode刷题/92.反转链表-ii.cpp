/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    // 在反转整个链表的基础上进行修改

    // 反转整个链表
    ListNode* reverseList(ListNode* head) {
        // 递归出口（只写head会出现单元素链表越界的问题，因此这里两个都写
        if (nullptr == head or nullptr == head->next)
            return head;

        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    // 反转链表的前n个
    ListNode* reverseN(ListNode* head, int n) {
        // 先把最后一个节点和后面断开并且记录后面节点
        auto p = head, pr = head;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                pr = p->next;
                p->next = nullptr;
                break;
            }
            p = p->next;
        }

        auto newHead = reverseList(head);
        head->next = pr;
        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // TODO
    }
};
// @lc code=end
