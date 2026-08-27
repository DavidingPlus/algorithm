/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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

    // 递归解法。
    ListNode *swapPairs(ListNode *head)
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        // 前面的特判保证了这里至少有两个节点。因此先反转头两个节点，再递归。
        ListNode *first = head, *second = head->next, *other = head->next->next;

        first->next = swapPairs(other);
        second->next = first;


        return second;
    }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
