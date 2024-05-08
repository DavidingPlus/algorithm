#include <iostream>
using namespace std;
#include "MyQueue.h"

namespace TestMyQueue {
void test() {
    MyQueue<int> mq;
    cout << "mq: " << (mq.isEmpty() ? "empty" : "not empty") << endl;

    mq.push(1);
    mq.push(2);
    mq.push(3);

    cout << mq.peek() << endl;
    cout << mq.pop() << endl;
    cout << mq.peek() << endl;

    cout << "mq: " << (mq.isEmpty() ? "empty" : "not empty") << endl;

    cout << endl
         << "-----------------------------------" << endl
         << endl;

    auto mq2 = mq;
    cout << "mq2: " << (mq.isEmpty() ? "empty" : "not empty") << endl;

    mq.push(100);

    cout << mq.peek() << endl;
    cout << mq.pop() << endl;
    cout << mq.peek() << endl;

    cout << "mq2: " << (mq.isEmpty() ? "empty" : "not empty") << endl;
}
}  // namespace TestMyQueue

int main() {
    TestMyQueue::test();

    return 0;
}
