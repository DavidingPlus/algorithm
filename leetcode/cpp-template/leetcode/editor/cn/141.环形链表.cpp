/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution
{

public:

    // 快慢指针，相交代表存在环。
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            // 判断条件放在后面，防止初始条件 fast == slow 直接结束，导致判断错误。
            if (fast == slow) return true;
        }


        return false;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
