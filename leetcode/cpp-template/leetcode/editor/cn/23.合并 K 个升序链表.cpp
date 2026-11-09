/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30404
 *
 * [23] 合并 K 个升序链表
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

    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        ListNode *dummyHead = new ListNode(-1), *pDummy = dummyHead;

        // 使用优先性队列（小顶堆实现），保证每次队列弹出的元素都是最小的。初始情况先把所有链表的首元素压进来，然后取出的元素对应的链表压入下一个元素，直到某个链表为空，退出战场，最终排序完成。
        std::priority_queue<ListNode *,
                            std::vector<ListNode *>,
                            std::function<bool(ListNode *, ListNode *)>>
            pq([](ListNode *node1, ListNode *node2)
               {
                   return node1->val > node2->val; //
               });

        // 把所有链表的首元素压进来。
        for (auto &head : lists)
        {
            // 空链表直接跳过，对应测试用例 [[]]。
            if (head) pq.push(head);
        }

        while (!pq.empty())
        {
            // 弹出队列首元素。
            auto node = pq.top();
            pq.pop();

            pDummy->next = new ListNode(node->val);
            pDummy = pDummy->next;

            // 压入下一个元素。
            if (node->next) pq.push(node->next);
        }


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
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
