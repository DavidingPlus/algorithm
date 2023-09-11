#include <iostream>
using namespace std;
#include "MyDeque.h"

namespace TestMyDeque {
void test_constructor() {
    MyDeque<int> md;

    auto md2 = md;
}
}  // namespace TestMyDeque

int main() {
    TestMyDeque::test_constructor();

    return 0;
}
