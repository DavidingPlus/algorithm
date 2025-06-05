#include <iostream>
using namespace std;

const int N = 100010;
int n;
int arr[N] = {0};

int __max(const int &val1, const int &val2) {
    return val1 >= val2 ? val1 : val2;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int res = 1;  // 0的位置必然为1

    // 用res数组来表示以位置为右端点的最长不包含重复数序列的长度
    // 每次的左端点的值看是不是需要往右移动，因为他已经是最左边的值了，再往左走就矛盾了
    for (int i = 1, j = 0; i < n; ++i) {
        int pre_j = j;
        bool flag = false;
        // 考虑 6 9 5 10 1 2 3 加入9
        // 就算重复也只可能重复一次，就将j放到他的后面就可以了
        while (j < i) {
            if (arr[j] == arr[i]) {
                flag = true;
                ++j;  // 新的序列的j位置
                break;
            }
            ++j;
        }

        // 出来之后判断j是否和i重合，可以用flag标记
        if (!flag)
            j = pre_j;

        res = __max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
