/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30404
 *
 * [25] K 个一组翻转链表
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

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head) return nullptr;

        // 1. 先反转以 head 开头的 k 个元素。
        ListNode *a = head, *b = head;
        for (int i = 0; i < k; ++i, b = b->next)
        {
            // 不足 k 个，返回剩余节点即可。
            if (!b) return head;
        }

        ListNode *newHead = reverse(a, b);

        // 2. 将第 k + 1 个元素作为 head 递归调用 reverseKGroup 函数。
        // 3. 将上述两个过程的结果连接起来。
        a->next = reverseKGroup(b, k);


        return newHead;
    }


private:

    // 这个工具函数用于反转 [a, b) 之间的元素。
    ListNode *reverse(ListNode *a, ListNode *b)
    {
        if (!a) return nullptr;

        // 递归边界：a->next == b 说明 a 是 [a, b) 中的最后一个节点。此时不能继续递归到 b，因为 b 是反转区间之外的第一个节点；直接返回 a，后续递归层再把前面的节点接到 a 后面。
        // 如果只判断 a == b，那么递归到最后一个节点时，newA 就是 b，接下来的 newA->next = a 会错误地修改区间外的 b 节点，同时还会导致新头节点返回错误。
        if (a->next == b) return a;

        ListNode *newA = a->next;

        ListNode *newHead = reverse(newA, b);
        newA->next = a;
        a->next = nullptr;


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
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
