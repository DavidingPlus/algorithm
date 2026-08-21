/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 虚拟头节点 + 双指针
        ListNode *dummyHead = new ListNode(-1, head);

        ListNode *fast = dummyHead, *slow = dummyHead;

        for (int i = 0; i < n; ++i) fast = fast->next;
        for (; fast->next; fast = fast->next) slow = slow->next;

        slow->next = slow->next->next;

        return dummyHead->next;
    }
};

// @lc code=end
