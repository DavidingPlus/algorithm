#include <iostream>
using namespace std;

int _cellToPowerTwo(int num) {
    // 这是私有成员，我给的数肯定是大于0的，所以这里就不判断了

    // 这是大佬的办法
    // --num;
    // num |= num >> 1;
    // num |= num >> 2;
    // num |= num >> 4;
    // num |= num >> 8;
    // num |= num >> 16;
    // ++num;

    // 我的办法
    int res = 1;
    while (res < num)
        res *= 2;

    return res;
}

int main() {
    int num;
    cin >> num;

    cout << _cellToPowerTwo(num) << endl;

    return 0;
}
