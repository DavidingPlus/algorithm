/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30404
 *
 * [61] 旋转链表
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

    ListNode *rotateRight(ListNode *head, int k)
    {
        // 特判 head 为空和 k 为 0 的情况，都不需要操作，直接返回原链表即可。
        if (!head || 0 == k) return head;

        // 核心思路是找到倒数第 k 个节点，将该节点前面的节点（不包含该节点）和该节点后面的节点（包含该节点）分开，将后面的链表和前面的链表连接即可。
        // 在实际操作中，如果 k 大于链表长度 n，在原题的语义中意味着旋转了一轮，实际等价于移动了 k % n 的长度。

        // 首先遍历一次链表得到长度 n。
        int n = 1;
        ListNode *tail = head;
        for (; tail->next; tail = tail->next) ++n;

        // 找到倒数第 k 个节点的前驱节点，即正数第 n - k 个节点。
        k %= n;
        // 如果 k 是链表长度 n 的整数倍，取模后 k 会变成 0，说明链表实际上不需要旋转。
        // 此时必须直接返回 head；否则 successor 会指向错误位置，可能导致返回空指针或断开链表。
        if (0 == k) return head;

        ListNode *successor = head;
        for (int i = 0; i < n - k - 1; ++i) successor = successor->next;

        // 修改移动操作后的状态。
        tail->next = head;
        head = successor->next;
        successor->next = nullptr;


        return head;
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
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
