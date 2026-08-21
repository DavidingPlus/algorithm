/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

#include "_listnode.h"


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

#include <bits/stdc++.h>


class Solution
{

public:

    // 递归解法
    ListNode *swapPairs(ListNode *head)
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode *headNext = head->next;
        ListNode *remain = head->next->next;

        head->next = swapPairs(headNext->next);
        headNext->next = head;

        return headNext;
    }
};

// @lc code=end
