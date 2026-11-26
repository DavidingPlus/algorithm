/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30404
 *
 * [148] 排序链表
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


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
class Solution
{

public:

    // 正确的一种解法：归并排序。
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) return head;

        ListNode *middlePrev = findMiddlePrevOfList(head), *middle = middlePrev->next;
        middlePrev->next = nullptr;

        return mergeTwoList(sortList(head), sortList(middle));
    }

    // 合并两个已经升序的链表，为一个升序的链表。
    ListNode *mergeTwoList(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1), *p = dummy, *p1 = head1, *p2 = head2;

        while (p1 && p2)
        {
            auto &node = p1->val < p2->val ? p1 : p2;

            p->next = node;
            p = p->next;
            node = node->next;
        }

        auto &remain = p1 ? p1 : p2;
        p->next = remain;


        return dummy->next;
    }

    // 找到链表的中点。本题的场景需要找到链表的中点的前驱结点，外层调用保证该链表至少有两个结点。
    ListNode *findMiddlePrevOfList(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fast = head, *slow = dummy;

        while (fast && fast->next) fast = fast->next->next, slow = slow->next;


        return slow;
    }


    // 废掉的解法：每次递归都要扫一遍链表，时间复杂度有点爆炸，需要考虑其他的做法。
    // ListNode *sortList(ListNode *head)
    // {
    //     if (!head || !head->next) return head;

    //     // 排序后面的部分。
    //     ListNode *remainHead = sortList(head->next);

    //     // 然后尝试将原 head 接入到后面部分，构成一条完整链表。依旧构造虚拟头结点方便操作。
    //     ListNode *dummyHead = new ListNode(std::numeric_limits<int>::min(), remainHead), *p = dummyHead;

    //     while (true)
    //     {
    //         if (p->next)
    //         {
    //             // 因为后半段已经有序，找到第一个大于 head->val 的结点插入即可（前面的值可能重复）。
    //             if (p->next->val > head->val)
    //             {
    //                 head->next = p->next;
    //                 p->next = head;

    //                 break;
    //             }
    //         }
    //         // p->next 为空代表 head 需要插入到末尾。
    //         else
    //         {
    //             p->next = head;
    //             head->next = nullptr;

    //             break;
    //         }


    //         p = p->next;
    //     }


    //     return dummyHead->next;
    // }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [4,19,14,5,-3,1,8,5,11,15]\n
// @lcpr case=end

 */
