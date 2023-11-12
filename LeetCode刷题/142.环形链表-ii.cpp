/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 相遇的时候快指针一定比慢指针多走了一倍
        // 然后我们把其中一个指针指向起点，再相遇的时候就是起点
        // 见142.png
        ListNode *fast = head, *slow = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (nullptr == fast or nullptr == fast->next)
            return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end
