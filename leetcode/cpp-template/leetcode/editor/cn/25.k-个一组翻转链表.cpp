/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start

/**
 * Definition for singly-linked std::list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    // 反转整个链表
    ListNode* reverseList(ListNode* head) {
        // 递归出口（只写head会出现单元素链表越界的问题，因此这里两个都写
        if (nullptr == head || nullptr == head->next)
            return head;

        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 一次递归，将前面k个和后面的拆开，如果长度不够就返回自身
        auto p = head, pr = head;
        for (int i = 0; i < k; ++i) {
            // 长度不够返回head即可
            if (nullptr == p)
                return head;

            if (k - 1 == i) {
                pr = p->next;
                p->next = nullptr;
                break;
            }
            p = p->next;
        }
        auto newHead = reverseList(head);
        head->next = reverseKGroup(pr, k);
        return newHead;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
