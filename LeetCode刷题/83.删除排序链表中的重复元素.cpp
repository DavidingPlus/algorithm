/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;

        // 还是快慢指针，只不过这一次完事之后需要把slow置空
        ListNode *
            fast = head,
           *slow = head, *slow_before = head;
        int pre = __INT_MAX__;

        for (; fast; fast = fast->next) {
            if (pre != fast->val) {
                slow->val = fast->val;
                pre = fast->val;

                // 我们要找到slow前面的指针
                if (head != slow)
                    slow_before = slow_before->next;
                slow = slow->next;
            }
        }

        slow_before->next = nullptr;

        return head;
    }
};
// @lc code=end
