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
        // 快慢指针，和数组那个题一样的思路
        auto slow = head, fast = head;
        while (fast) {
            if (nullptr == fast->next || fast->val != fast->next->val) {
                slow->val = fast->val;

                // 这里需要做一个特判，由于最后一个赋值一定是最后一个元素，由于slow出来是下一个元素，无法置空，所以在这里判断
                if (nullptr == fast->next)
                    slow->next = nullptr;

                slow = slow->next;
            }
            fast = fast->next;
        }

        return head;
    }
};
// @lc code=end
