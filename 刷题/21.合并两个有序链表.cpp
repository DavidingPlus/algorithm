/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    void insert_after(ListNode* node, const int& val) {
        ListNode* newnode = new ListNode(val);
        newnode->next = node->next;
        node->next = newnode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 使用两根指针，分别从两个链表开始往后移
        // 哪个小就把谁的插入到新链表中，然后指针往后移
        ListNode* ret_list = new ListNode(-1);  // 需要一个虚拟头结点，方便插数据

        ListNode *move1 = list1, *move2 = list2, *move_ret = ret_list;
        while (move1 && move2) {
            // 比较大小
            ListNode*& smaller = (move1->val <= move2->val) ? move1 : move2;

            insert_after(move_ret, smaller->val);
            move_ret = move_ret->next;
            smaller = smaller->next;
        }

        // 最后肯定会剩下一个不为空
        ListNode*& remain = move1 ? move1 : move2;
        // 把剩下的插入
        for (; remain; remain = remain->next) {
            insert_after(move_ret, remain->val);
            move_ret = move_ret->next;
        }

        // 删去虚拟头结点
        ret_list = ret_list->next;

        return ret_list;
    }
};
// @lc code=end
