/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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

    void reorderList(ListNode *head)
    {
        // 本题相当于是头部一个，尾部一个。因此需要得到尾部链表的序列，可以顺序遍历然后使用栈存储。
        std::stack<ListNode *> st;
        ListNode *p = head;
        for (; p; p = p->next) st.push(p);

        p = head;
        ListNode *lastNode = st.top();
        // 处理边界条件，结合样例分析，两个条件分别对应奇数和偶数的情况。题目保证链表不为空。
        while (p != lastNode && p->next != lastNode)
        {
            ListNode *next = p->next;

            lastNode->next = next;
            p->next = lastNode;
            p = next;

            st.pop();
            lastNode = st.top();
        }

        // 断开链表尾部。
        lastNode->next = nullptr;
    }


    // 旧版代码。
    // void reorderList(ListNode *head)
    // {
    //     // 利用双端队列让链表头部一个，尾部一个（这里用数组模拟双端队列）

    //     std::vector<ListNode *> vec;

    //     for (auto pMove = head; pMove; pMove = pMove->next) vec.push_back(pMove);

    //     ListNode *dummyHead = new ListNode(-1, nullptr);

    //     ListNode *pMove = dummyHead;
    //     for (int left = 0, right = vec.size() - 1; left <= right; ++left, --right)
    //     {
    //         pMove->next = vec[left];
    //         pMove = pMove->next;

    //         if (left != right)
    //         {
    //             pMove->next = vec[right];
    //             pMove = pMove->next;
    //         }
    //     }

    //     // 最后一个指针的末尾需要额外设置为空，不然会内存越界，切记细节！
    //     pMove->next = nullptr;
    //     head = dummyHead->next;
    // }
};

// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}
