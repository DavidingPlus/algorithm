/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        // 把链表转化为数组，再套用之前的方法即可
        vector<int> v;
        for (auto p = head; p; p = p->next) v.push_back(p->val);

        // 单调栈
        vector<int> res(v.size());
        stack<int> s;
        for (int i = res.size() - 1; i >= 0; --i) {
            while (false == s.empty() and v[i] >= s.top()) s.pop();
            res[i] = s.empty() ? 0 : s.top();
            s.push(v[i]);
        }
        return res;
    }
};
// @lc code=end
