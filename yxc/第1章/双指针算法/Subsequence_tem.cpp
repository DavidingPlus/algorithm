#include <iostream>
using namespace std;

const int N = 100010;
int n;
int arr[N] = {0}, s[N] = {0};

int __max(const int &val1, const int &val2) {
    return val1 >= val2 ? val1 : val2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 1;  // 0的位置必然为1

    // 用res数组来表示以位置为右端点的最长不包含重复数序列的长度
    // 每次的左端点的值看是不是需要往右移动，因为他已经是最左边的值了，再往左走就矛盾了

    // 从1开始，需要计入arr[0]在s数组中的次数
    ++s[arr[0]];

    for (int i = 1, j = 0; i < n; ++i) {
        // 答案的思路
        // 用一个s[]数组来存储j到i之间每一个数出现的次数，出现多了就把j向后移动直到为1次
        ++s[arr[i]];  // 现在只有可能这个东西不为1
        while (s[arr[i]] > 1) {
            --s[arr[j]];
            ++j;
        }

        res = __max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
