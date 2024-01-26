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
#include <functional>
#include <map>
#include <queue>
#include <vector>

class Solution {
public:
    // 使用multimap的方法
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode* res = new ListNode(-1);
    //     auto p = res;

    //     // 先用map/multimap这一套做，再用优先性队列做
    //     multimap<int, ListNode*, less<int>> mm;

    //     // 先把所有链表的首元素放进来
    //     for (auto& head : lists)
    //         if (head)
    //             mm.insert({head->val, head});

    //     // 由于按照值从小到大排序，所以每次从头部取出元素，然后后移即可
    //     while (!mm.empty()) {
    //         p->next = new ListNode(mm.begin()->first);
    //         p = p->next;
    //         auto tmp = mm.begin()->second;  // 先弹出，所以用中间量保存一下
    //         // 弹出头部，插入新的
    //         mm.erase(mm.begin());
    //         if (tmp->next)
    //             mm.insert({tmp->next->val, tmp->next});
    //     }

    //     return res->next;
    // }

    // 使用优先性队列的方法
    // class Pred {
    //     bool operator()(ListNode* node1, ListNode* node2) {
    //         return node1->val > node2->val;
    //     }
    // };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(-1);
        auto p = res;

        // 优先性队列（二叉堆），例如最小堆，能通过上浮或者下沉的操作保证每次的插入和删除操作之后容器是有序的
        // priority_queue<ListNode*, vector<ListNode*>, Pred> pq;

        // TODO
        // 这个用仿函数做谓词失败了，我也不知道为什么，但是学到了可以在模板参数中使用function模板类做占位，然后在构造参数中写出具体的lambda，这样在leetcode里面不会报错，头文件是<functional>
        priority_queue<ListNode*, vector<ListNode*>,
                       function<bool(ListNode*, ListNode*)> >
            pq([](ListNode* node1, ListNode* node2) {
                return node1->val > node2->val;
            });

        // 先把所有链表的首元素放进来
        for (auto& head : lists)
            if (head)
                pq.push(head);

        // 由于按照值从小到大排序，所以每次从头部取出元素，然后后移即可
        while (!pq.empty()) {
            p->next = new ListNode(pq.top()->val);
            p = p->next;
            auto tmp = pq.top();  // 先弹出，所以用中间量保存一下
            // 弹出头部，插入新的
            pq.pop();
            if (tmp->next)
                pq.push(tmp->next);
        }

        return res->next;
    }
    // @lc code=end
};
