/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <vector>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = new ListNode(-1);
        ListNode* p = ret;

        // 就是合并2个链表的翻版，重点是我选择什么容器来存储
        // 选set会报错，我不知道为什么...，在仿函数的位置报错了，我得研究一下
        // TODO
        multimap<int, ListNode*, less<int>> m;
        for (auto& head : lists)
            if (head)
                m.insert({head->val, head});

        // 每次从头部读取一个，然后完事之后修改该元素的值，如此重复，直到map为空
        while (!m.empty()) {
            p->next = new ListNode(m.begin()->first);
            p = p->next;

            auto node = m.begin()->second->next;
            m.erase(m.begin());
            if (node)
                m.insert({node->val, node});
        }

        ret = ret->next;

        return ret;
    }
};
// @lc code=end
