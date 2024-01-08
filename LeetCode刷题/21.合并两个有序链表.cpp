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
        ListNode* res = new ListNode(-1);  // 构造虚拟头结点
        ListNode *p1 = list1, *p2 = list2, *p = res;

        while (p1 and p2) {
            auto& smaller = (p1->val <= p2->val) ? p1 : p2;
            p->next = new ListNode(smaller->val);
            smaller = smaller->next;
            p = p->next;
        }
        auto& remain = p1 ? p1 : p2;
        while (remain) {
            p->next = new ListNode(remain->val);
            remain = remain->next;
            p = p->next;
        }

        // 弹掉虚拟头结点
        res = res->next;
        return res;
    }
};
// @lc code=end
