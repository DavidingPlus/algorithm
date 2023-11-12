/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
#include <vector>

class Solution {
public:
    // 方法1：迭代做一次
    // ListNode* reverseList(ListNode* head) {
    //     // 拿一个数组存
    //     vector<int> vals;

    //     ListNode* p = head;
    //     while (p) {
    //         vals.push_back(p->val);
    //         p = p->next;
    //     }

    //     p = head;
    //     int i = 0;
    //     while (p) {
    //         p->val = vals[vals.size() - 1 - i++];
    //         p = p->next;
    //     }

    //     return head;
    // }

    // 方法2：用递归做
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head or nullptr == head->next)
            return head;

        // 反转后面的链表
        auto last = reverseList(head->next);
        // 并且反转之后把后面的链表加上自己变成一个新的反转链表，注意最后要是空，为了保持主问题和子问题的统一
        head->next->next = head;
        head->next = nullptr;

        return last;
    }
};
// @lc code=end
