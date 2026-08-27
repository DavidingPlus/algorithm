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

    // 解法 2：将原链表反转得到新链表，然后与原链表进行一一比对。
    // 用头插法构造一条新的反转链表。
    // ListNode *reverseList(ListNode *head)
    // {
    //     ListNode *dummyHead = new ListNode(-1);

    //     for (ListNode *p = head; p; p = p->next)
    //     {
    //         ListNode *node = new ListNode(p->val);

    //         node->next = dummyHead->next;
    //         dummyHead->next = node;
    //     }


    //     return dummyHead->next;
    // }

    // bool isPalindrome(ListNode *head)
    // {
    //     ListNode *reverseHead = reverseList(head);
    //     ListNode *p = head, *pReverse = reverseHead;

    //     while (p)
    //     {
    //         if (p->val != pReverse->val) return false;
    //         p = p->next, pReverse = pReverse->next;
    //     }


    //     return true;
    // }


    // 解法 3：找到链表的中点，把后面的反转，然后进行比较。
    ListNode *middleNode(ListNode *head)
    {
        // 快慢指针。
        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 本题目中需要找到右半边的第一个，因此 fast 如果不是 nullptr 就是奇数，需要返回 slow->next。
        return fast ? slow->next : slow;
    }

    // 使用递归法原地反转链表。
    ListNode *reverseList(ListNode *head)
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;


        return newHead;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head) return true;

        ListNode *rightHead = middleNode(head);
        ListNode *reverseHead = reverseList(rightHead);

        ListNode *pLeft = head, *pRight = reverseHead;
        // 反转后的右半部分长度不超过左半部分，因此以 pRight 为空作为结束条件。如果写成 while (pLeft)，单节点或奇数长度链表比较完右半部分后，pRight 可能已经为空，继续访问 pRight->val 会发生空指针解引用。
        while (pRight)
        {
            if (pLeft->val != pRight->val) return false;
            pLeft = pLeft->next, pRight = pRight->next;
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
