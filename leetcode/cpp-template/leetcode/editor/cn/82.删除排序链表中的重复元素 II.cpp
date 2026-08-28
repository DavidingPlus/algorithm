/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30404
 *
 * [82] 删除排序链表中的重复元素 II
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

    // 解法 1：双指针。

    // 版本 1。
    // ListNode *deleteDuplicates(ListNode *head)
    // {
    //     ListNode *fast = head, *slow = head;
    //     // 记录 fast 的前驱节点，为保证头部统一，使用 dummyHead 连接原链表头部。
    //     ListNode *dummyHead = new ListNode(-101, head), *predecessorFast = dummyHead, *predecessorSlow = dummyHead;

    //     for (; fast; fast = fast->next)
    //     {
    //         // 判断条件是当前结点的前驱结点和后继结点的值（或后继结点为空）都不相同。
    //         if (fast->val != predecessorFast->val && (!fast->next || fast->val != fast->next->val))
    //         {
    //             slow->val = fast->val;

    //             predecessorSlow = slow;
    //             slow = slow->next;
    //         }

    //         predecessorFast = fast;
    //     }

    //     predecessorSlow->next = nullptr;


    //     return dummyHead->next;
    // }

    // 版本 2（优化）。
    // ListNode *deleteDuplicates(ListNode *head)
    // {
    //     // 当前结点和下一个结点值相同，说明进入了重复区间，跳过这个区间即可。
    //     ListNode dummyHead(-101, head);
    //     // fast 指针用于遍历原链表。
    //     // slow 指针指向最后一个需要保留的节点。例如 [1, 2, 3, 3, 4]，fast 遍历 3 的时候，slow 指向 2。在这个语义下，需要 dummyHead 来辅助。
    //     ListNode *fast = head, *slow = &dummyHead;

    //     while (fast)
    //     {
    //         // 遇到重复区间。
    //         if (fast->next && fast->val == fast->next->val)
    //         {
    //             int val = fast->val;
    //             // 跳过重复区间直到下一个值。
    //             while (fast && val == fast->val) fast = fast->next;
    //             // 把 slow->next 指向 fast，即跳过了这段重复区间。例如 [1, 2, 3, 3, 4]，上面 fast 指向 4 时跳出，这时候 slow 为 2，2 -> 4 即跳过了重复区间 3。
    //             slow->next = fast;
    //         }
    //         // 不重复。
    //         else
    //         {
    //             // slow 正常往后移动。
    //             slow = fast;
    //             fast = fast->next;
    //         }
    //     }


    //     return dummyHead.next;
    // }

    // 解法 2：递归。
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) return nullptr;
        if (!head->next) return head;

        // 如果头结点和身后节点的值不同，则对之后的链表去重即可。
        if (head->val != head->next->val)
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }

        // 如果如果头结点和身后节点的值相同，则说明从 head 开始存在若干重复节点，越过重复节点，找到 head 之后那个不重复的节点。
        // 这里已经包含了 head->next 为空的考虑，如果 head->next 为空，代表整条链表都是重复的，这时递归结果为空，符合语义。
        while (head->next && head->val == head->next->val) head = head->next;
        return deleteDuplicates(head->next);
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
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */
