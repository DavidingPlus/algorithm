#include "ListNode.h"

#include <iostream>


ListNode::ListNode() : val(0), next(nullptr)
{
}

ListNode::ListNode(int x) : val(x), next(nullptr)
{
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next)
{
}

ListNode *ListNode::createHead(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void ListNode::print(const ListNode *head)
{
    const ListNode *current = head;
    while (current)
    {
        std::cout << current->val;
        if (current->next)
            std::cout << "->";
        current = current->next;
    }
    std::cout << std::endl;
}

void ListNode::freeList(ListNode *head)
{
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}
