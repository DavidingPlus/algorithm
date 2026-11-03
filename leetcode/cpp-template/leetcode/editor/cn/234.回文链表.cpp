/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

/**
 * Definition for singly-linked std::list.
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

    // 解法 1：将链表中的元素放入数组当中，可以随机访问，这个太无脑了，不用。

    // 解法 2：将原链表反转得到新链表，然后与原链表进行一一比对。（头插法）
    // ListNode *reverseList(ListNode *head)
    // {
    //     if (!head || !head->next) return head;

    //     ListNode *dummyHead = new ListNode(-1, nullptr);

    //     for (ListNode *p = head; p; p = p->next)
    //     {
    //         ListNode *newNode = new ListNode(p->val, dummyHead->next);
    //         dummyHead->next = newNode;
    //     }


    //     return dummyHead->next;
    // }

    // bool isPalindrome(ListNode *head)
    // {
    //     if (!head) return true;

    //     ListNode *reverseListHead = reverseList(head);

    //     for (ListNode *p1 = head, *p2 = reverseListHead; p1 && p2; p1 = p1->next, p2 = p2->next)
    //     {
    //         if (p1->val != p2->val) return false;
    //     }


    //     return true;
    // }


    // 解法 3：找到链表的中点，把后面的反转，然后进行比较。
    ListNode *middleNode(ListNode *head)
    {
        if (!head | !head->next) return head;

        // 快慢指针。
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) fast = fast->next->next, slow = slow->next;


        // 本题目中需要找到右半边的第一个，因此 fast 如果不是 nullptr 就是奇数，需要返回 slow->next。
        return fast ? slow->next : slow;
    }

    // 使用递归法原地反转链表。
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next) return head;

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;


        return newHead;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next) return true;

        for (ListNode *pLeft = head, *pRight = reverseList(middleNode(head)); pLeft && pRight; pLeft = pLeft->next, pRight = pRight->next)
        {
            if (pLeft->val != pRight->val) return false;
        }


        return true;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
