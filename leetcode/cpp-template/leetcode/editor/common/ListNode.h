#ifndef LEETCODE_COMMON_LISTNODE_INCLUDED
#define LEETCODE_COMMON_LISTNODE_INCLUDED

#include <vector>


class ListNode
{

public:

    int val;
    ListNode *next;

    ListNode();

    explicit ListNode(int x);

    ListNode(int x, ListNode *next);

    static ListNode *createHead(const std::vector<int> &values);

    static void print(const ListNode *head);

    static void freeList(ListNode *head);
};


#endif
