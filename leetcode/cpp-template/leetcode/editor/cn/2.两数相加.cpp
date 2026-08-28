/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30404
 *
 * [2] 两数相加
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

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(-1), *pDummy = dummyHead;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;

        // // 处理都有位数的部分。
        // for (; p1 && p2; p1 = p1->next, p2 = p2->next)
        // {
        //     int val = (p1->val + p2->val + carry) % 10;
        //     carry = (p1->val + p2->val + carry) / 10;

        //     ListNode *node = new ListNode(val);
        //     pDummy->next = node;
        //     pDummy = pDummy->next;
        // }

        // // 处理后面不同位的部分。
        // auto &p = p1 ? p1 : p2;
        // for (; p; p = p->next)
        // {
        //     int val = (p->val + carry) % 10;
        //     carry = (p->val + carry) / 10;

        //     pDummy->next = new ListNode(val);
        //     pDummy = pDummy->next;
        // }

        // // 若最后有进位，需要额外补 1。
        // if (carry)
        // {
        //     pDummy->next = new ListNode(1);
        //     pDummy = pDummy->next;
        // }

        // 这三个阶段的处理可以合并。循环运行的条件是 p1 不为空或者 p2 不为空或者进位 carry 不为 0。
        while (p1 || p2 || carry)
        {
            int val = carry;

            // 这两个 if 的判断包含了处理都有位数的部分和处理后面不同位的部分。
            if (p1)
            {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2)
            {
                val += p2->val;
                p2 = p2->next;
            }

            // 如果 p1 和 p2 都为空，carry 有值的话，也会走到这里处理最后有进位的逻辑。
            carry = val / 10;
            val = val % 10;

            pDummy->next = new ListNode(val);
            pDummy = pDummy->next;
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
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
