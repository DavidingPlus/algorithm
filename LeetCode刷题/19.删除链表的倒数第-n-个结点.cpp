/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

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

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
    // 方法1：烂，需要处理头结点的特殊情况
    //  ListNode* getKthFromEnd(ListNode* head, int k) {
    //      // 遍历一次即可，倒数第k个
    //      // 我们让一个指针先走k次，然后另一根指针从头开始
    //      // 这个时候往后走n-k+1刚好就是先出发的指针到达null，然后第二根指针就在n-k+1的位置，就是倒数第k个

    //     // 在这个题里面如果没走完就有move1为nullptr则说明走过了，返回头结点
    //     ListNode* move1 = head;
    //     int i = 0;
    //     for (; move1 && i < k; ++i)
    //         move1 = move1->next;

    //     if (!move1 && i < k)
    //         return nullptr;

    //     ListNode* ret = head;
    //     while (move1) {
    //         move1 = move1->next;
    //         ret = ret->next;
    //     }

    //     return ret;
    // }

    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     // 需要注意有可能删除的结点没有前置结点，这个时候就是删除头结点
    //     ListNode* target_prior = getKthFromEnd(head, n + 1);
    //     if (!target_prior)
    //         head = head->next;
    //     else
    //         target_prior->next = target_prior->next->next;

    //     return head;
    // }

    // 2.方法2：使用虚拟头结点
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 遍历一次即可，倒数第k个
        // 我们让一个指针先走k次，然后另一根指针从头开始
        // 这个时候往后走n-k+1刚好就是先出发的指针到达null，然后第二根指针就在n-k+1的位置，就是倒数第k个

        ListNode* move1 = head;
        for (int i = 0; i < k; ++i)
            move1 = move1->next;

        ListNode* ret = head;
        while (move1) {
            move1 = move1->next;
            ret = ret->next;
        }

        return ret;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 给原链表加一个虚拟头结点
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* target_prior = getKthFromEnd(dummy, n + 1);
        target_prior->next = target_prior->next->next;

        return dummy->next;  // 这里需要返回dummy->next，因为删除头结点的时候是把虚拟头结点指针置为空，但是head未被真正删除
    }
};
// @lc code=end
