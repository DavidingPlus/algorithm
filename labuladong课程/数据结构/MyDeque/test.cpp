#include <iostream>
using namespace std;
#include "MyDeque.h"

template <typename value_type>
void print_linkedlist(MyDeque<value_type>& list) {
    list.traverse([](value_type& val) { cout << val << ' '; });
    cout << endl;
}

namespace TestMyDeque {

void test_constructor() {
    MyDeque<int> md{1, 2, 3, 4, 5, 6};
    print_linkedlist(md);

    MyDeque<int> md2 = md;
    md2[0] = -10;
    print_linkedlist(md2);
}

void test_insert() {
    MyDeque<int> md{1, 2, 3, 4, 5, 6};

    md.push_back(100);
    print_linkedlist(md);

    md.push_front(50);
    print_linkedlist(md);

    md.insert(7, 101);
    print_linkedlist(md);

    md.insert(9, 99);
    print_linkedlist(md);

    md.insert(11, 102);
    print_linkedlist(md);
}

void test_remove() {
    MyDeque<int> md{1, 2, 3, 4, 5, 6};

    cout << md.pop_back() << endl;
    print_linkedlist(md);

    cout << md.pop_front() << endl;
    print_linkedlist(md);

    cout << md.remove(3) << endl;
    print_linkedlist(md);

    // 后面是测试能否弹空的
    // cout << md.pop_back() << endl;
    // print_linkedlist(md);

    // cout << md.pop_back() << endl;
    // print_linkedlist(md);

    // cout << md.pop_back() << endl;
    // print_linkedlist(md);
}

void test_get_set_operator() {
    MyDeque<int> md{1, 2, 3, 4, 5, 6};

    cout << md.get(2) << endl;
    cout << md.front() << endl;
    cout << md.back() << endl;

    cout << md[5] << endl;

    md[4] = 9;
    md.set(3, -10);
    print_linkedlist(md);

    cout << md.get(6) << endl;
}

void test_clear() {
    MyDeque<int> md{1, 2, 3, 4, 5, 6};
    print_linkedlist(md);

    md.clear();

    md.push_back(1);
    md.push_back(1);
    md.push_back(1);
    print_linkedlist(md);
}

}  // namespace TestMyDeque

int main() {
    TestMyDeque::test_constructor();

    // TestMyDeque::test_insert();

    // TestMyDeque::test_remove();

    // TestMyDeque::test_get_set_operator();

    // TestMyDeque::test_clear();

    return 0;
}
