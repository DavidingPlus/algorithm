/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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

    void reorderList(ListNode *head)
    {
        // 利用双端队列让链表头部一个，尾部一个（这里用数组模拟双端队列）

        std::vector<ListNode *> vec;

        for (auto pMove = head; pMove; pMove = pMove->next) vec.push_back(pMove);

        ListNode *dummyHead = new ListNode(-1, nullptr);

        ListNode *pMove = dummyHead;
        for (int left = 0, right = vec.size() - 1; left <= right; ++left, --right)
        {
            pMove->next = vec[left];
            pMove = pMove->next;

            if (left != right)
            {
                pMove->next = vec[right];
                pMove = pMove->next;
            }
        }

        // 最后一个指针的末尾需要额外设置为空，不然会内存越界，切记细节！
        pMove->next = nullptr;
        head = dummyHead->next;
    }
};

// @lc code=end
