/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include "_listnode.h"

#include <bits/stdc++.h>

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

class Solution
{

public:

    ListNode *deleteDuplicates(ListNode *head)
    {
        // 快慢指针，和数组那个题一样的思路。
        ListNode *fast = head, *slow = head;

        for (; fast; fast = fast->next)
        {
            if (slow->val < fast->val)
            {
                slow->next->val = fast->val;
                slow = slow->next;
            }
        }

        // 特判一下，因为输入链表可能为空。
        if (slow) slow->next = nullptr;


        return head;
    }
};
// @lc code=end


int main()
{
}
