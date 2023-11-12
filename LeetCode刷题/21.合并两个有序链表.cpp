/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);  // 给定一个虚拟头结点
        ListNode *l1 = list1, *l2 = list2, *p = head;

        // 两个都不为空
        while (nullptr != l1 and nullptr != l2) {
            auto& smaller = (l1->val <= l2->val) ? l1 : l2;
            p->next = new ListNode(smaller->val);
            p = p->next;
            smaller = smaller->next;
        }
        // 其中一个先为空
        auto& l = (nullptr != l1) ? l1 : l2;
        while (l) {
            p->next = new ListNode(l->val);
            p = p->next;
            l = l->next;
        }

        // 弹掉虚拟头结点
        head = head->next;

        return head;
    }
};
// @lc code=end
