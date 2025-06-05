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

// 这个程序我们通过递归的方式来打印数组和链表
void print_array_recursion(const vector<int>& nums, int index) {
    if (nums.size() == index) {
        cout << endl;
        return;
    }

    cout << nums[index] << ' ';
    print_array_recursion(nums, index + 1);
}

void print_array_recursion(const vector<int>& nums) {  // 封装一下
    print_array_recursion(nums, 0);
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
    vector<int> arr{1, 2, 3, 4, 5};

    ListNode node1(5);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(2);
    ListNode node5(1);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    print_array_recursion(arr);

    print_list_recursion(&node1);

    return 0;
}
