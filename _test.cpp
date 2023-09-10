#include <iostream>
using namespace std;

int main() {
    int* data;

    data = new int[5]{1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i)
        cout << data[i] << ' ';
    cout << endl;

    return 0;
}
