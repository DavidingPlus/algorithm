#include <iostream>
using namespace std;
#include <vector>

class ListNode {
public:
    ListNode() = default;

    ListNode(int val) : val(val) {}

public:
    int val = 0;
    class ListNode* next = nullptr;
};

// 三个问题
// 1.递归求出链表的长度
int size(ListNode* head, int count) {
    if (!head)
        return count;

    return size(head->next, ++count);
}

int size(ListNode* head) {
    return size(head, 0);
}

// 倒序递归打印链表
void print_list_recursion_reverse(ListNode* head, int) {
    if (!head)
        return;

    print_list_recursion_reverse(head->next, 1);
    // 后序遍历位置
    cout << head->val << ' ';
}

void print_list_recursion_reverse(ListNode* head) {
    print_list_recursion_reverse(head, 1);

    cout << endl;
}

// 倒序递归打印数组
void print_array_recursion_reverse(const vector<int>& nums, int index) {
    if (nums.size() == index)
        return;

    print_array_recursion_reverse(nums, index + 1);
    // 后续遍历位置
    cout << nums[index] << ' ';
}

void print_array_recursion_reverse(const vector<int>& nums) {
    print_array_recursion_reverse(nums, 0);
    cout << endl;
}

int main() {
    // 链表
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    cout << size(&node1) << endl;

    print_list_recursion_reverse(&node1);

    // 数组
    vector<int> arr{5, 4, 3, 2, 1};
    print_array_recursion_reverse(arr);

    return 0;
}
