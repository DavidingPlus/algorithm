/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 处理链表的题目，构造虚拟头节点会好很多，因为这样把头节点和后面节点的操作做了统一。
        ListNode *res = new ListNode(-1);
        ListNode *p1 = list1, *p2 = list2, *p = res;

        // 两个链表都没走到底。
        while (p1 && p2)
        {
            auto &smaller = p1->val <= p2->val ? p1 : p2;
            p->next = new ListNode(smaller->val);
            p = p->next;
            smaller = smaller->next;
        }

        // 一个走到底了，把另一个链表剩余的部分接到 res 末尾。
        auto &remain = p1 ? p1 : p2;
        p->next = remain;

        // 弹掉虚拟头节点。
        return res->next;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
