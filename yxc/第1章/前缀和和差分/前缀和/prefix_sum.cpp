#include <iostream>
using namespace std;
#include <vector>

vector<int> Prefix_Sum(const vector<int>& vec) {
    vector<int> ans;
    ans.push_back(0);  // 边界条件 S0=0

    for (int i = 1; i < vec.size(); ++i)
        ans.push_back(ans[i - 1] + vec[i]);

    return ans;
}

int main() {
    // 这段代码
    // 好处：提高cin读取速度
    // 坏处：不能再使用scanf了
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> array;
    array.push_back(0);  // 将第一个数存为0

    // 输入数组
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        array.push_back(num);
    }

    // 得到前缀和数组
    vector<int> Prefix_Sum_Arr = Prefix_Sum(array);

    // 开始询问
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        cout << Prefix_Sum_Arr[end] - Prefix_Sum_Arr[start - 1] << endl;
    }

    return 0;
}
