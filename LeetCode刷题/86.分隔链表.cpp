/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        // 给定两个指针，第一个指针只关心小于x的节点，另一个只关心大于等于x的
        ListNode *l1 = head, *l2 = head;
        ListNode* res = new ListNode(-1);
        ListNode* l = res;

        while (l1) {
            if (l1->val < x) {
                l->next = new ListNode(l1->val);
                l = l->next;
            }
            l1 = l1->next;
        }
        while (l2) {
            if (l2->val >= x) {
                l->next = new ListNode(l2->val);
                l = l->next;
            }
            l2 = l2->next;
        }

        res = res->next;

        return res;
    }
};
// @lc code=end
