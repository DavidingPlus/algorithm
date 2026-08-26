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

    // 迭代解法。
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *p = head, *pDummy = dummyHead;
        int i = 1;

        // 先处理前面的部分。直接把 dummyHead->next 接到 head 即可。
        dummyHead->next = head;
        // 然后通过遍历拿到需要反转链表的首元素指针。
        for (; i < left; ++i) p = p->next, pDummy = pDummy->next;

        ListNode *reverseTail = nullptr;

        // 处理中间反转链表的部分。
        for (; i <= right; ++i)
        {
            ListNode *node = new ListNode(p->val);

            // 第一个节点最终会成为反转链表的尾节点，提前记录下来防止后面重新遍历。
            if (!reverseTail) reverseTail = node;

            p = p->next;
            node->next = pDummy->next, pDummy->next = node;
        }

        // 处理后面的部分。把反转链表的末尾和后面的部分连上即可。
        reverseTail->next = p;


        return dummyHead->next;
    }

    // TODO 递归解法。
    // ListNode *reverseBetween(ListNode *head, int left, int right)
    // {
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
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
