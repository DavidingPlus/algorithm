/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */


#include "../common/globalmacros.h"
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

    ListNode *partition(ListNode *head, int x)
    {
        // 创建两个链表，遍历一次就行。
        ListNode *smaller = new ListNode(-1), *bigger = new ListNode(-1);
        ListNode *p = head, *pSmaller = smaller, *pBigger = bigger;

        while (p)
        {
            auto &target = p->val < x ? pSmaller : pBigger;
            target->next = new ListNode(p->val);
            target = target->next;
            p = p->next;
        }

        pSmaller->next = bigger->next;


        return smaller->next;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
