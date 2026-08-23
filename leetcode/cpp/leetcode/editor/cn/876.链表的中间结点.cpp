/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */



#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

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

    ListNode *middleNode(ListNode *head)
    {
        // 快慢指针，快指针一次两步，慢指针一次一步。
        ListNode *fast = head, *slow = head;
        // 这个条件能保证当前节点以及当前节点的后继节点不为空，这样 fast->next->next 不会发生内存泄漏。
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }


        return slow;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
