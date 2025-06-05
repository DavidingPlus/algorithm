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
        // 创建两个链表，遍历一次就行
        auto res = new ListNode(-1),
             res2 = new ListNode(-1);
        auto p = head, p1 = res, p2 = res2;
        while (p) {
            auto& pp = p->val < x ? p1 : p2;
            pp->next = new ListNode(p->val);
            pp = pp->next;
            p = p->next;
        }

        p1->next = res2->next;

        return res->next;
    }
};
// @lc code=end
