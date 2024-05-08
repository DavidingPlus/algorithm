#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

const int N = 300010;
int n, m;

vector<pair<int, int>> _data;  // 用来记录最开始的x和c的情况
vector<int> _map;              // 映射数组
int _map2[N];                  // 映射数组，存储映射后的下标和实际的数值的关系
int Presum[N];                 // 前缀和数组

// 找到第一个大于等于他的数的下标
int __binary_search(const vector<int>& arr, int left, int right, int target, bool& ok) {
    if (left == right)
        return left;

    while (left != right) {
        // 找从左到右第一个数，这个数左边均小于他，右边均不小于他
        int mid = left + right >> 1;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    // 如果找不到修改ok的值
    if (arr[left] != target)
        ok = false;

    return left;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int x, c;
        scanf("%d%d", &x, &c);
        _data.push_back(make_pair(x, c));
        _map.push_back(x);
    }

    // 将_map数组去重，排序，然后为了使用前缀和将第一位设置为0
    sort(_map.begin(), _map.end(), less<int>());               // 排序
    _map.erase(unique(_map.begin(), _map.end()), _map.end());  // 去重

    // 更改数组_map2，将映射坐标和实际值做连接
    for (auto val : _data) {
        // 由于_map数组没有加上前置0，所以这里需要加上一位，_map2里面是有前置0的
        bool ok = true;
        int index = 1 + __binary_search(_map, 0, _map.size() - 1, val.first, ok);
        _map2[index] += val.second;
    }

    // 求出前缀和
    for (int i = 1; i <= _map.size(); ++i)
        Presum[i] = Presum[i - 1] + _map2[i];

    // 询问
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);

        // 如果l比_map数组最大值还大，那么不用找了，为0
        // 如果r比_map数组最大值还大，那么修改r为最大值的点
        if (l > _map.back()) {
            cout << 0 << endl;
            continue;
        }
        if (r > _map.back())
            r = _map.back();

        // 这个坐标得到的是映射出来不小于这个点的下标
        // 但是我们区间应该这么看，如果找不到，左边的应该自动匹配到存在的右边的第一个，右边的应该自动移到左边的第一个

        // 比如     1 3 7
        // 映射 (0) 1 2 3
        // 现在求4和6之间的，都找不到，把4移动到7的位置，6移动到3的位置，然后由于左边的大于右边的，则区间长度为0

        //_l找到的是第一个比他大的._r找到的是第一个比他小的
        bool ok = true, flag_r = true;
        int _l = 1 + __binary_search(_map, 0, _map.size() - 1, l, ok);
        int _r = 1 + __binary_search(_map, 0, _map.size() - 1, r, flag_r);

        // 只有右边的映射可能需要左移一位，因为找不到
        if (!flag_r)
            --_r;

        if (_l > _r)
            cout << 0 << endl;
        else
            cout << Presum[_r] - Presum[_l - 1] << endl;
    }

    return 0;
}
