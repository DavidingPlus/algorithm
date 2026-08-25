#include <cassert>
#include <iostream>

#include "../ListNode.h"


int main()
{
    assert(ListNode::createHead({}) == nullptr);

    ListNode *head = ListNode::createHead({1, 2, 3});
    assert(head != nullptr);
    assert(head->val == 1);
    assert(head->next != nullptr && head->next->val == 2);
    assert(head->next->next != nullptr && head->next->next->val == 3);
    assert(head->next->next->next == nullptr);

    std::cout << "ListNode:" << std::endl;
    ListNode::print(head);

    ListNode::freeList(head);
    std::cout << "ListNode test passed" << std::endl;
}
