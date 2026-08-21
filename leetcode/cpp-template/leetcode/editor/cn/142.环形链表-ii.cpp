/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include "_listnode.h"


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>


class Solution
{

public:

    ListNode *detectCycle(ListNode *head)
    {
        // 相遇的时候快指针一定比慢指针多走了一倍
        // 然后我们把其中一个指针指向起点，再相遇的时候就是起点
        // 见 142.png

        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            // TODO 这里不能把 fast != slow 的条件判断放在 while 循环中，因为一开始 fast == slow，也就是循环进不来，需要让他迭代几次再说，因此需要放在里面
            if (fast == slow) break;
        }

        if (!fast || !fast->next) return nullptr;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

// @lc code=end
