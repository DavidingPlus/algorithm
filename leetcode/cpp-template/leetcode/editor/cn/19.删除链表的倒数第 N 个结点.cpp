/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30404
 *
 * [19] 删除链表的倒数第 N 个结点
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


class Solution
{

public:


    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(-1, head), *fast = dummyHead, *slow = dummyHead;

        // 双指针思路，快指针先走 n 步，然后快慢指针从头开始同时走，当快指针走到 nullptr 的时候，慢指针刚好就是倒数第 n 个节点。
        // 本题需要找到倒数第 n 个节点的前驱节点，为保证头节点的语义一致，使用 dummy head。
        while (n--) fast = fast->next;
        while (fast->next) fast = fast->next, slow = slow->next;

        slow->next = slow->next->next;


        return dummyHead->next;
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
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
