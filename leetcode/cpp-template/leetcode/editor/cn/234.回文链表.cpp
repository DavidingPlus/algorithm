/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    // 我想到了两个方法
    // 1.将链表中的元素放入数组当中，可以随机访问，这个太无脑了，不用
    // 2.将原链表反转得到新链表，然后与原链表进行一一比对

    // // 用头插法构造一条新的反转链表
    // ListNode *reverseList(ListNode *head) {
    //     auto res = new ListNode(-1);

    //     for (auto p = head; p; p = p->next) {
    //         auto newNode = new ListNode(p->val);
    //         newNode->next = res->next;
    //         res->next = newNode;
    //     }

    //     return res->next;
    // }

    // bool isPalindrome(ListNode *head) {
    //     auto newList = reverseList(head);

    //     auto p1 = head, p2 = newList;
    //     while (p1) {
    //         if (p1->val != p2->val)
    //             return false;
    //         p1 = p1->next;
    //         p2 = p2->next;
    //     }

    //     return true;
    // }

    // 方法3：找到链表的中点，把后面的反转，然后进行比较
    ListNode* middleNode(ListNode* head) {
        // 快慢指针
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 为了本题目的要求，需要找到右半边的第一个，因此fast如果不是nullptr就是奇数
        if (fast)
            slow = slow->next;

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
            return head;

        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        bool isOdd = false;
        auto mid = middleNode(head);

        auto newHead = reverseList(mid);
        auto pl = head, pr = newHead;

        while (pr) {
            if (pr->val != pl->val)
                return false;
            pl = pl->next;
            pr = pr->next;
        }
        return true;
    }
};
// @lc code=end
