/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

    // 迭代解法
    ListNode *reverseList(ListNode *head)
    {
        // 构造一个新的链表进行头插
        ListNode *dummyHead = new ListNode(-1, nullptr);

        for (auto pMove = head; pMove; pMove = pMove->next)
        {
            ListNode *newNode = new ListNode(pMove->val);

            newNode->next = dummyHead->next;
            dummyHead->next = newNode;
        }

        return dummyHead->next;
    }

    // 递归解法
    // ListNode *reverseList(ListNode *head)
    // {
    //     if (!head) return nullptr;
    //     if (!head->next) return head;

    //     auto headPrior = reverseList(head->next);

    //     head->next->next = head;
    //     head->next = nullptr;

    //     return headPrior;
    // }
};
// @lc code=end
