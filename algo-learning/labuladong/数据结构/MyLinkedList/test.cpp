#include <iostream>
using namespace std;
#include "MyLinkedList.h"

template <typename value_type>
void print_linkedlist(MyLinkedList<value_type>& list) {
    list.traverse([](value_type& val) { cout << val << ' '; });
    cout << endl;
}

namespace TestMyLinkedList {

void test_constructor() {
    MyLinkedList<int> ll{1, 2, 3, 4, 5, 6};
    print_linkedlist(ll);

    MyLinkedList<int> ll2 = ll;
    ll2[0] = -10;
    print_linkedlist(ll2);
}

void test_insert() {
    MyLinkedList<int> ll{1, 2, 3, 4, 5, 6};

    ll.push_back(100);
    print_linkedlist(ll);

    ll.push_front(50);
    print_linkedlist(ll);

    ll.insert_after(7, 101);
    print_linkedlist(ll);

    ll.insert_before(9, 99);
    print_linkedlist(ll);

    ll.insert_before(11, 102);
    print_linkedlist(ll);
}

void test_remove() {
    MyLinkedList<int> ll{1, 2, 3, 4, 5, 6};

    cout << ll.pop_back() << endl;
    print_linkedlist(ll);

    cout << ll.pop_front() << endl;
    print_linkedlist(ll);

    cout << ll.remove(3) << endl;
    print_linkedlist(ll);

    // 后面是测试能否弹空的
    // cout << ll.pop_back() << endl;
    // print_linkedlist(ll);

    // cout << ll.pop_back() << endl;
    // print_linkedlist(ll);

    // cout << ll.pop_back() << endl;
    // print_linkedlist(ll);
}

void test_get_set_operator() {
    MyLinkedList<int> ll{1, 2, 3, 4, 5, 6};

    cout << ll.get(2) << endl;
    cout << ll.front() << endl;
    cout << ll.back() << endl;

    cout << ll[5] << endl;

    ll[4] = 9;
    ll.set(3, -10);
    print_linkedlist(ll);

    cout << ll.get(6) << endl;
}

void test_clear() {
    MyLinkedList<int> ll{1, 2, 3, 4, 5, 6};
    print_linkedlist(ll);

    ll.clear();

    ll.push_back(1);
    ll.push_back(1);
    ll.push_back(1);
    print_linkedlist(ll);
}

}  // namespace TestMyLinkedList

int main() {
    TestMyLinkedList::test_constructor();

    // TestMyLinkedList::test_insert();

    // TestMyLinkedList::test_remove();

    // TestMyLinkedList::test_get_set_operator();

    // TestMyLinkedList::test_clear();

    return 0;
}
