/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void insert_after(ListNode* node, const int& val) {
        ListNode* newnode = new ListNode(val);
        newnode->next = node->next;
        node->next = newnode;
    }

    ListNode* partition(ListNode* head, int x) {
        // 我们可以把小于x值存入一个链表，然后大于等于的存入一个链表
        ListNode* smaller_list = new ListNode(-1);  // 虚拟头结点
        ListNode* bigger_list = new ListNode(-1);

        // 工作指针
        ListNode *move = head, *move_smaller = smaller_list, *move_bigger = bigger_list;

        for (; move; move = move->next) {
            if (move->val < x) {
                insert_after(move_smaller, move->val);
                move_smaller = move_smaller->next;
            }
            else{
                
            }
        }
    }
};
// @lc code=end
