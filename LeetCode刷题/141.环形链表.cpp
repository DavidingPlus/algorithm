/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针，快指针前进一步，慢指针前进两步
        // 如果没有环，则两个最后都为nullptr
        // 如果有环，两个最终必然相遇，fast超过了slow一圈

        ListNode *fast = head, *slow = head;
        // 如果没有环是快指针先变为空
        // 由于快指针走两步，需要判断fast和fast->next是否都为空，否则很可能出现内存泄漏
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // 相遇表示有环
            if (fast == slow)
                return true;
        }

        // 退出表示没环
        return false;
    }
};
// @lc code=end
