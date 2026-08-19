/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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

        // 这个题和上个题的区别是上个题是把重复的变为一个，这个题是把所有的重复的全都去掉
        // 快慢指针
        // 快指针遇到新元素和后面的比较看是否重复，不重复则慢指针记录
        ListNode *fast = head, *slow = head, *slow_before = head;
        while (fast) {
            // 新的元素，判断和后面是否相等或者是最后一个
            if (!fast->next || fast->val != fast->next->val) {
                slow->val = fast->val;
                fast = fast->next;

                if (head != slow)
                    slow_before = slow_before->next;
                slow = slow->next;
            } else {
                // 将fast指针后移直到遇到下一个元素
                while (fast->next && fast->val == fast->next->val)
                    fast = fast->next;

                if (!fast->next)  // 扫到最后了都重复
                    break;

                // 后移到新元素处
                fast = fast->next;
            }
        }

        // 特判，这里如果出来slow还在原地说明全部重复
        if (head == slow)
            return nullptr;
        slow_before->next = nullptr;

        return head;
    }
};
// @lc code=end
