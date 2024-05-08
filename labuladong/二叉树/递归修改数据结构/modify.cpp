#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode() = default;

    ListNode(int val) : val(val) {}

public:
    int val = 0;
    class ListNode* next = nullptr;
};

// 这个程序我们通过递归的方式来修改链表(太巧妙了!!)
// 注意这里我们必须让这个函数有一个返回值，因为我们需要前面的值去接受addLast的结果，我们在代码里去看
// 总结：递归修改数据结构，一定要让函数有一个返回值!!!
ListNode* addLast(ListNode* head, int val) {
    if (!head)
        return new ListNode(val);

    // 我们思考一下这个函数应该返回什么，我们从最后一个来看
    // 例如1 2 3 4 5，5现在调用，那么head->next进去为空，返回一个新的结点，那我应该让他与其链上，代码符合
    // 然后返回head都能保证被上层正确链接到，已经链接上再链接一次也无妨
    head->next = addLast(head->next, val);

    return head;
}

// 类似的思路
ListNode* removeLast(ListNode* head) {
    if (!head->next)
        return nullptr;

    head->next = removeLast(head->next);

    return head;
}

void print_list_recursion(ListNode* head) {
    if (nullptr == head) {
        cout << endl;
        return;
    }

    cout << head->val << ' ';
    print_list_recursion(head->next);
}

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    addLast(&node1, 6);

    print_list_recursion(&node1);

    removeLast(&node1);

    print_list_recursion(&node1);

    return 0;
}
