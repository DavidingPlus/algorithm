/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
#include <vector>

class Solution {
public:
    // 方法1：迭代做一次
    // ListNode* reverseList(ListNode* head) {
    //     // 头插法
    //     auto res = new ListNode(-1);

    //     for (auto ph = head; ph; ph = ph->next) {
    //         auto newNode = new ListNode(ph->val);
    //         newNode->next = res->next;
    //         res->next = newNode;
    //     }
    //     return res->next;
    // }

    // 方法2：用递归做
    ListNode* reverseList(ListNode* head) {
        // 递归出口（只写head会出现单元素链表越界的问题，因此这里两个都写
        if (nullptr == head or nullptr == head->next)
            return head;

        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
// @lc code=end
