#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

const int N = 100010;
int n;
vector<pair<int, int>> arr;  // 区间数组
vector<pair<int, int>> res;  // 结果数组

int __max_(const int& val1, const int& val2) {
    return val1 >= val2 ? val1 : val2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        arr.push_back(make_pair(l, r));
    }

    // 先讲区间按照左端点进行排序
    sort(arr.begin(), arr.end(), [=](pair<int, int> val1, pair<int, int> val2) {
        return val1.first <= val2.first;
    });

    int start = arr[0].first, end = arr[0].second;
    // 排序之后进行区间合并
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i].first <= end)  // 如果是前两种情况 表示可以合并
            end = __max_(end, arr[i].second);
        else {  // 不可合并
            res.push_back(make_pair(start, end));
            start = arr[i].first;
            end = arr[i].second;
        }
    }

    // 将最后一个区间存进去
    // 我们的代码逻辑倒数第二个区间和最后一个区间不管是哪种情况最后一次都是走上面，最后一个区间没输出
    res.push_back(make_pair(start, end));

    cout << res.size() << endl;

    return 0;
}
