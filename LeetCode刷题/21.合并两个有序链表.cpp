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
        // 处理链表的题目，构造一个虚拟头节点会好很多，因为这样把头节点和后面节点的操作做了统一
        ListNode* res = new ListNode(-1);

        auto p1 = list1, p2 = list2, p = res;

        // 两个链表都没走到底
        while (nullptr != p1 and nullptr != p2) {
            auto& smaller = (p1->val <= p2->val) ? p1 : p2;
            p->next = new ListNode(smaller->val);
            p = p->next;
            smaller = smaller->next;
        }
        // 一个走到底了
        auto& remain = (nullptr != p1) ? p1 : p2;
        while (nullptr != remain) {
            p->next = new ListNode(remain->val);
            p = p->next;
            remain = remain->next;
        }

        res = res->next;  // 弹掉虚拟头节点
        return res;
    }
};
// @lc code=end
