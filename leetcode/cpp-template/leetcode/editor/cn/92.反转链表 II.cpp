/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30404
 *
 * [92] 反转链表 II
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

    // 解法 1：迭代。
    // ListNode *reverseBetween(ListNode *head, int left, int right)
    // {
    //     ListNode *dummyHead = new ListNode(-1);
    //     ListNode *p = head, *pDummy = dummyHead;
    //     int i = 1;

    //     // 先处理前面的部分。直接把 dummyHead->next 接到 head 即可。
    //     dummyHead->next = head;
    //     // 然后通过遍历拿到需要反转链表的首元素指针。
    //     for (; i < left; ++i) p = p->next, pDummy = pDummy->next;

    //     ListNode *reverseTail = nullptr;

    //     // 处理中间反转链表的部分。
    //     for (; i <= right; ++i)
    //     {
    //         ListNode *node = new ListNode(p->val);

    //         // 第一个节点最终会成为反转链表的尾节点，提前记录下来防止后面重新遍历。
    //         if (!reverseTail) reverseTail = node;

    //         p = p->next;
    //         node->next = pDummy->next, pDummy->next = node;
    //     }

    //     // 处理后面的部分。把反转链表的末尾和后面的部分连上即可。
    //     reverseTail->next = p;


    //     return dummyHead->next;
    // }

    // 解法 2：递归。
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head) return nullptr;
        if (left == right) return head;

        // 1 == left，说明当前节点就是反转区间的起点。
        if (1 == left)
        {
            return reverseN(head, right);
        }
        // 否则递归寻找。
        else
        {
            head->next = reverseBetween(head->next, left - 1, right - 1);
            return head;
        }
    }

    // 存储从 head 开始的第 n + 1 个结点，即不用翻转的第一个结点。
    ListNode *successor = nullptr;

    // 反转从 head 开始的后 n 个结点。
    ListNode *reverseN(ListNode *head, int n)
    {
        // 剩余一个结点需要反转的时候，记录后继结点，并直接返回原链表。
        // 因为下面是后序操作，因此轮到赋值的时候 successor 已经被赋值好了。
        if (1 == n)
        {
            successor = head->next;
            return head;
        }

        ListNode *newHead = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;


        return newHead;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
