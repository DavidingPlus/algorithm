/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
#include <stack>

class Solution {
public:
    void reorderList(ListNode *head) {
        // 如何让单链表从尾部从前面输出呢?
        // 可以借助栈的特点，从头存进去，然后pop出来就是反向的了

        stack<ListNode *> s;
        int len = 0;
        for (auto p = head; p; p = p->next, ++len)
            s.push(p);

        // 然后原链表一个，尾部链表一个，直到到达长度
        auto p = head;

        // 走到一半的位置，注意我们的p每一个都是指向原链表的下一个位置，跳过插入的位置，因此就会剩下一半，最后剩的一个也需要做处理
        for (int i = 0; i < len / 2; ++i) {
            auto node = s.top();
            s.pop();

            auto tmp = p->next;
            node->next = p->next;
            p->next = node;
            p = tmp;
        }
        p->next = nullptr;
    }
};
// @lc code=end
