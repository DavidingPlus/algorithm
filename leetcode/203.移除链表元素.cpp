/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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

    // 常规迭代解法
    ListNode *removeElements(ListNode *head, int val)
    {
        // 链表题目都可以考虑的思路，设置虚拟头节点
        ListNode *dummyHead = new ListNode(-1, head);

        auto pMove = dummyHead;
        while (pMove)
        {
            if (pMove->next && val == pMove->next->val)
            {
                // 参考数据 [7, 7, 7, 7] 删除 7，知道删除以后当前结点的 next 是不确定的，只有判断成功以后才能继续往后移动
                pMove->next = pMove->next->next;
            }
            else
            {
                pMove = pMove->next;
            }
        }

        return dummyHead->next;
    }

    // 递归解法
    // ListNode *removeElements(ListNode *head, int val)
    // {
    //     if (!head) return nullptr;

    //     auto headNext = removeElements(head->next, val);

    //     if (val != head->val) head->next = headNext;

    //     return val != head->val ? head : headNext;
    // }
};

// @lc code=end
