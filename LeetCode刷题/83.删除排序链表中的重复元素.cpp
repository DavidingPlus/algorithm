/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head)
            return nullptr;

        // 同数组的那个一样的思路
        auto fast = head, slow = head;

        while (fast) {
            if (nullptr == fast->next or fast->val != fast->next->val) {
                slow->val = fast->val;
                if (fast->next)
                    slow = slow->next;
            }
            fast = fast->next;
        }

        slow->next = nullptr;

        return head;
    }
};
// @lc code=end
