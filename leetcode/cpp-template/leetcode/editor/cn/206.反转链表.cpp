/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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


    // 迭代解法。
    // ListNode *reverseList(ListNode *head)
    // {
    //     // 构造一个新的链表进行头插。
    //     ListNode *dummyHead = new ListNode(-1);

    //     for (ListNode *p = head; p; p = p->next)
    //     {
    //         ListNode *node = new ListNode(p->val);

    //         node->next = dummyHead->next;
    //         dummyHead->next = node;
    //     }


    //     return dummyHead->next;
    // }

    // 递归解法。
    ListNode *reverseList(ListNode *head)
    {
        if (!head) return nullptr;
        // 下面要用到 head->next，不能为空，因此需要特判。
        if (!head->next) return head;

        ListNode *newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;


        return newHead;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
