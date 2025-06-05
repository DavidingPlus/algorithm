#include <iostream>
using namespace std;
#include "MyStack.h"

namespace TestMyStack {
void test() {
    MyStack<int> ms;
    cout << "ms: " << (ms.isEmpty() ? "empty" : "not empty") << endl;

    ms.push(1);
    ms.push(2);
    ms.push(3);

    cout << ms.get() << endl;
    cout << ms.pop() << endl;
    cout << ms.get() << endl;

    cout << "ms: " << (ms.isEmpty() ? "empty" : "not empty") << endl;

    cout << endl
         << "-----------------------------------" << endl
         << endl;

    auto ms2 = ms;
    cout << "ms2: " << (ms.isEmpty() ? "empty" : "not empty") << endl;

    ms.push(100);

    cout << ms.get() << endl;
    cout << ms.pop() << endl;
    cout << ms.get() << endl;

    cout << "ms2: " << (ms.isEmpty() ? "empty" : "not empty") << endl;
}
}  // namespace TestMyStack

int main() {
    TestMyStack::test();

    return 0;
}
