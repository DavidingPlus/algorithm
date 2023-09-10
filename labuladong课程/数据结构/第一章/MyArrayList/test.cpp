#include <iostream>
using namespace std;
#include "MyArrayList.h"

int main() {
    MyArrayList<int> al{1, 2, 3, 4, 1, 34};
    auto al2(al);

    al.tranverse([](int& val) { cout << val << ' '; });
    cout << endl;

    al2.tranverse([](int& val) { cout << ++val << ' '; });
    cout << endl;

    return 0;
}
